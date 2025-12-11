package Threading;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.Scanner;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

public class Client {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        try (Socket socket = new Socket("localhost", 6666)) {
            System.out.println("Connection established");
            System.out.println("Remote port: " + socket.getPort());
            System.out.println("Local port: " + socket.getLocalPort());

            // buffers
            ObjectOutputStream out = new ObjectOutputStream(socket.getOutputStream());
            ObjectInputStream in = new ObjectInputStream(socket.getInputStream());

            try (Scanner scanner = new Scanner(System.in)) {
                System.out.println("Enter User Name");
                String UserName = scanner.nextLine();
                out.writeObject(UserName);
                out.flush();

                String msg = (String) in.readObject();
                System.out.println(msg);
                
                if(msg.equals("Username already taken. Connection closing.")) {
                    System.out.println("USername already in use!!!");
                    socket.close();
                    return;
                }   
                
                boolean created = in.readBoolean();

                if(created) {
                    System.out.println("Directory created");
                } else {
                    System.out.println("Directory already exists");
         }

         
         
         System.out.println("Login Successful");
         while (true) {

            //user command dibe client theke
            System.out.println("Enter Command: ");
            String command = scanner.nextLine();

            //ebare etake server e pathacchi
            out.writeObject(command);
            out.flush();

            if(command.equalsIgnoreCase("Send list")){
                String userList = (String) in.readObject();
                System.out.println("User List: \n" + userList);
            }

            if(command.equalsIgnoreCase("log out")){
                String logoutMsg = (String) in.readObject();
                System.out.println(logoutMsg);
                System.out.println("Connection closing...");
                break;
            }

            if(command.equalsIgnoreCase("upload")){
                //file name ar size nibo user input nbo
                System.out.println("Enter file path to upload: ");
                String filePath = scanner.nextLine();
                System.out.println("Public or Private ?: ");
                String privacy = scanner.nextLine();

                File file = new File(filePath);


                if(!file.exists() || !file.isFile()) {
                    System.out.println("File does not exist. Try again.");
                    continue;
                }


                String fileName = file.getName();
                long fileSize = file.length();
                //ebar server ke pathabo

                out.writeObject(fileName);
                out.writeLong(fileSize);
                out.writeObject(privacy);   
                out.flush();

                String uploadStatus = (String) in.readObject();
                if(uploadStatus.equalsIgnoreCase("Reject")){
                    System.out.println("Upload rejected.");
                    continue;

                }

                String fileID = (String) in.readObject();
                int chunkSize = in.readInt();
                System.out.println("Upload Accepted.");
                System.out.println("File ID: " + fileID);
                System.out.println("Chunk Size: " + chunkSize);
                System.out.println("Privacy: " + privacy);

                FileInputStream fis = new FileInputStream(file);
                long sent = 0;
               // int loopcount = 0;

                while(sent < fileSize) {
                    int toSend = (int)Math.min(chunkSize, fileSize - sent);
                    byte[] buffer = fis.readNBytes(toSend);
                    out.write(buffer);
                    out.flush();

                    String ack = (String) in.readObject();
                    if(ack.startsWith("Chunk no : ")) {
                        System.out.println(ack);
                    }
                    else{
                        System.out.println("Chunk is not acknowledged !!!");
                    }
                    sent += toSend;

                }

                fis.close();





                String done = (String) in.readObject();
                System.out.println(done);


            }

            if(command.equalsIgnoreCase("download")){
                //ONNO CLIENT ER PUBLIC FILE DOWNLOAD KORBO
                
                //age public file gula show korbo with their id and input dite bolbo user ke je konta download korte chay

                String publicFiles = (String) in.readObject();
                System.out.println("Public Files: \n" + publicFiles);
                String privateFiles = (String) in.readObject();
                System.out.println("Your Files: \n" + privateFiles);

                System.out.println("Enter File ID to download: ");
                String fileID = scanner.nextLine();

                out.writeObject(fileID);
                out.flush();
                String response = (String) in.readObject();
                if(response.equalsIgnoreCase("File Not Found")){
                    System.out.println("File not found on server. Try again.");
                    continue;
                }


                String fileName = (String) in.readObject();
                long fileSize = in.readLong();
                int chunkSize = in.readInt();

                File downloadTo = new File("DownloadedFiles/"+ UserName);

                downloadTo.mkdirs();

                File outputFile = new File(downloadTo, fileName);
                FileOutputStream fos = new FileOutputStream(outputFile);    

                long received = 0;


                while(received < fileSize){


                    int bytesToRead = (int)Math.min(chunkSize, fileSize - received);
                    byte[] buffer = new byte[bytesToRead];
                    in.readFully(buffer);

                    fos.write(buffer, 0, bytesToRead);
                    received += bytesToRead;
                }
                
                fos.close();

                System.out.println("File " + fileName + " downloaded successfully.");
            }


            if(command.equalsIgnoreCase("Look up own files")){
                String ownFiles =(String) in.readObject();
                System.out.println("Your Files: \n" + ownFiles);


            }

            if(command.equalsIgnoreCase("Look up user files")){
                System.out.println("Enter username to look up: ");
                String lookupUser = scanner.nextLine();
                out.writeObject(lookupUser);
                out.flush();

                String userFiles = (String) in.readObject();
                System.out.println("Files of " + lookupUser + ":\n" + userFiles);
            }

            if(command.equalsIgnoreCase("Look up all public files")){

                String allPublicFiles = (String) in.readObject();
                System.out.println("All Public Files: \n" + allPublicFiles);
                

            }

            if(command.equalsIgnoreCase("Look up client list")){
                String clientList = (String) in.readObject();
                System.out.println("\nClient List: \n" + clientList);
            }

            if(command.equalsIgnoreCase("See ")){

            }

         }
            }
        }
    }
}
