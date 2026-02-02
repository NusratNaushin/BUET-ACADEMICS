import java.awt.*;
import java.io.*;
import java.net.Socket;
import java.net.SocketTimeoutException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import static java.lang.Integer.parseInt;

public class Client {
    private static Socket socket;

    public static void receiveFile(String filename, ObjectInputStream in, ObjectOutputStream out) {
        try {
            String path = "Downloads/";
            File directory = new File(path);

            if (!directory.exists()) {
                directory.mkdir();
            }
            // get file size
            long filesize = (long) in.readObject();
            System.out.println("Downloading " + filename + " of size " + filesize);
            File file=new File("Downloads/" + filename);

            FileOutputStream fos = new FileOutputStream(file);
            BufferedOutputStream bos = new BufferedOutputStream(fos);

            String acknowledge = "";
            int bytesread = 0;
            int total = 0;

            while (true) {
                Object o = in.readObject();
                if( o.getClass().equals(acknowledge.getClass() ) ){
                    acknowledge = (String) o;
                    break;
                }
                byte[] con = (byte[]) o;
                bytesread = con.length;
                total += bytesread;
                bos.write(con, 0, bytesread);
//                Thread.sleep(1000);
                // simulate timeout
//                if(count == 6){
//                    Thread.sleep(31000);
//                    continue;
//                }
            }
            bos.flush();
            bos.close();
            fos.close();

            System.out.println(acknowledge);
            if(acknowledge.equalsIgnoreCase("COMPLETED")){
                System.out.println(" File download completed");
            }

        }catch(Exception e){
            System.out.println(e);
        }

    }

    public static void sendFile(ObjectOutputStream out, ObjectInputStream in){
        try{
            System.out.println("Upload file from the dialogue");
            FileDialog dialog = new FileDialog((Frame)null, "Select File to Open");
            dialog.setMode(FileDialog.LOAD);
            dialog.setVisible(true);
            System.out.println(dialog.getDirectory() + dialog.getFile() + " chosen. ");
            File upload = new File(dialog.getDirectory() + dialog.getFile() );
            // send file name
            System.out.println("Choose a filename : ");
            Scanner sc= new Scanner(System.in);
            String filename = sc.nextLine();
            out.writeObject(filename);
            // send file size
            long length = upload.length();
            out.writeObject(length);
            // check if buffer is available
            boolean available = (boolean) in.readObject();
            if(available == false){
                System.out.println("Buffer limit exceeded");
                return;
            }
            // get chunk size from server
            int chunk_size = (int) in.readObject();
            System.out.println("Chunk size : " + chunk_size);
            // get file ID
            int fileID = (int) in.readObject();
            InputStream is = new FileInputStream(upload); //create an inputstream from the file
            byte[] buf = new byte[chunk_size]; //create buffer
            int len = 0;
            int count = 0;
            socket.setSoTimeout(30000);
            while ((len = is.read(buf)) != -1) {
                //os.write(buf, 0, len); //write buffer
                // copy buf to len array
                if(len == chunk_size){
                    out.writeObject(buf);
                }
                else{
                    byte[] buf2 = new byte[len];
                    System.arraycopy(buf, 0, buf2, 0, len);
                    out.writeObject(buf2);
                }
                out.reset();
                String confirmation = (String) in.readObject();
                System.out.println(confirmation);
                Thread.sleep(1000);
                count += 1;
                // simulate failure to mismatch filesize
//                if(count == 5){
//                    break;
//                }
            }
            out.writeObject("COMPLETED");
            is.close();
            String check = (String) in.readObject();
            if(check.equalsIgnoreCase("SUCCESS")){
                System.out.println("File transfer successful");
            }
            else if(check.equalsIgnoreCase("FAILURE")){
                System.out.println("File transfer failed");
            }
        }
        catch(SocketTimeoutException se){
            System.out.println(se);
            try{
                out.writeObject("Timeout");
            }
            catch (Exception e){
                System.out.println(e);
            }

        }
        catch(Exception e){
            System.out.println(e);
        }

    }

    public static void main(String[] args) throws IOException, ClassNotFoundException {
        socket = new Socket("localhost", 6666);
        System.out.println("Connection established");
        // buffers
        ObjectOutputStream out = new ObjectOutputStream(socket.getOutputStream());
        ObjectInputStream in = new ObjectInputStream(socket.getInputStream());

        Scanner sc= new Scanner(System.in); //System.in is a standard input stream

        // send student id
        while(true){
            System.out.println("Enter your student id : ");
            String id = sc.nextLine();
            out.writeObject(id);

            boolean login = (boolean) in.readObject();
            if(login == true){
                System.out.println("Successful login");
                break;
            }
            // user with id is already logged in
            System.out.println("User is already logged in");
        }


        //
        while(true) {
            //print menu
            System.out.println("1. Lookup Students\t 2. Your Files\t 3. Lookup a Student's file\t 4. Request File\t 5. View\t 6. Upload\t 7. Logout");
            String option = sc.nextLine();
            out.writeObject(option);

            if( option.equalsIgnoreCase("1") ){
                // user wish to see the user list
                // active_users : all the users currently online
                ArrayList<String> active_users = (ArrayList<String>) in.readObject();
                // users : all the users logged in at least once
                String[] users = (String[]) in.readObject();
                // print the users
                for(int i=0; i<users.length; i++) {
                    String user_name = users[i];
                    // identify the ones who are currently active
                    if(active_users.contains(user_name)){
                        user_name += ": online";
                    }
                    System.out.println(user_name);

                }
            }
            else if( option.equalsIgnoreCase("2") ){
                // see all your files
                for(int i = 0 ; i < 2 ; i++ ){
                    // i = 0 : public files
                    // i = 1 : private files
                    ArrayList<String> public_files =  (ArrayList<String>) in.readObject();
                    for(int j = 0; j < public_files.size() ; j++){
                        System.out.println(public_files.get(j));
                    }
                }
                System.out.println("Do you want to download any file?\n1. Yes\t     2. No ");
                // download : 1. Yes : wants to download a file ; 2. No : doesn't want to download a file
                String download = sc.nextLine();
                out.writeObject(download);
                if(download.equalsIgnoreCase("1")){
                    // wants to download a file
                    System.out.println("Write the id of the file you want to download : ");
                    // write filename and send it
                    String filename = sc.nextLine();
                    int fileid;
                    try{
                        fileid = Integer.parseInt(filename);
                        out.writeObject(fileid);
                    }
                    catch (Exception e){
                        out.writeObject("failed");
                        continue;
                    }
                    String available = (String) in.readObject();
                    if(available.equalsIgnoreCase("exists")){
                        filename = (String) in.readObject();
                        receiveFile(filename, in, out);
                    }
                    else{
                        System.out.println("File doesn't exist with the id : " + filename );
                    }

                }
                else if(download.equalsIgnoreCase("2")){
                    // doesn't want to download a file
                    continue;
                }
            }
            else if( option.equalsIgnoreCase("3") ){
                // Lookup and download other students' files
                System.out.println("Mention the student ID :");
                // read the student id
                String id = sc.nextLine();
                out.writeObject(id);
                Object o = in.readObject();
                Integer check = 0;
                // check determines if a student with id exists. If doesn't exist, Server will send an Integer with value 0
                if( o.getClass().equals( check.getClass() ) ){
                    check = (Integer) o;
                    if( check == 0 ){
                        System.out.println(id + " is not in the user list");
                        // No such user with id so continue
                        continue;
                    }
                }
                // results contain all the public files list of user with id
                List<String> results = (List<String>) o;
                System.out.println(id + " - public files : ");
                for( int i = 0 ; i < results.size() ; i++ ){
                    System.out.println(results.get(i));
                }
                System.out.println("Do you want to download a file?\n1. Yes\t 2. No");
                String download = sc.nextLine();
                // If user wants to download a file  - 1. Yes   2. No
                out.writeObject(download);
                if(download.equalsIgnoreCase("1")){
                    // user wants to download a file
                    System.out.println("Mention the filename : ");
                    String filename = sc.nextLine();
                    // write the filename to server
                    out.writeObject(filename);
                    String available = (String) in.readObject();
                    if(available.equalsIgnoreCase("exists")){
                        receiveFile(filename, in, out);
                    }
                    else{
                        System.out.println("No such file with filename : " + filename );
                    }

                }
                else if(download.equalsIgnoreCase("2")){
                    // user doesn't want to download a file
                    continue;
                }
            }
            else if( option.equalsIgnoreCase("4") ){
                // user wants to request for a file
                System.out.println("Enter description for your request : ");
                String description = sc.nextLine();
                out.writeObject(description);
            }
            else if( option.equalsIgnoreCase("5") ){
                // user wants to see unread messages
                // see others requests
                System.out.println("Requests : ");
                ArrayList<String> other_req = (ArrayList<String>) in.readObject();
                for(String s : other_req){
                    System.out.println("Request ID : " + s);
                }
                // see updates on your request
                ArrayList<String> own_req = (ArrayList<String>) in.readObject();
                System.out.println("Uploads for your requests : ");
                for(String s : own_req){
                    System.out.println("Request ID : " + s);
                }
            }
            else if( option.equalsIgnoreCase("6") ){
                // user wants to upload a file
                System.out.println("1. Public\t     2.Private\t     3. Grant Request");
                // type : 1. Public file    2. Private file
                String type = sc.nextLine();
                // send type of file
                out.writeObject(type);
                if( type.equalsIgnoreCase("3") ){
                    System.out.println("Enter request id ");
                    int req_id = parseInt(sc.nextLine());
                    out.writeObject( req_id );
                    // check if request id is valid, if not then continue
                    boolean check = (boolean) in.readObject();
                    if( check == false ){
                        System.out.println("No such request id exists");
                        continue;
                    }
                }
                if(type.equalsIgnoreCase("1") | type.equalsIgnoreCase("2" ) | type.equalsIgnoreCase("3") ){
                    sendFile(out, in);
                }

            }
            else if( option.equalsIgnoreCase("7") ){
                // user wants to logout
                in.close();
                out.close();
                socket.close();
                System.out.println("Logging out and exiting");
                System.exit(0);
            }
        }
    }
}
