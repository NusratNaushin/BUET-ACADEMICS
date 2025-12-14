package OFFLINE_2105168;

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
                    System.out.println("Username already in use!!!");
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
            System.out.println("\nOptions:\n1.Send List\n2.Upload\n3.Download\n4.Upload On Request\n5.View Unread Messages\n6.Look Up Own FIles\n7.Look Up User Files \n8.Look Up All Public files\n9.Log Out\n");
            System.out.println("Enter Command: \n");
            String command = scanner.nextLine();

            //ebare etake server e pathacchi
            out.writeObject(command);
            out.flush();

            if(command.equalsIgnoreCase("Send list")){     
                String userList = (String) in.readObject();          //client server er kase user list chabe so srver theke nibo list erjonne in readobject
                System.out.println("\nUser List: \n" + userList);
            }

            if(command.equalsIgnoreCase("log out")){
                String logoutMsg = (String) in.readObject();
                System.out.println(logoutMsg);
                System.out.println("Connection closing...");
                break;              //while loop theke ber hoye jabo 
            }

            if(command.equalsIgnoreCase("upload")){
                //file name ar size nibo user input nbo
                System.out.println("\nIs it on request? [yes/no]: \n");   //upload dui rokomer keu nijer theke upload korbe othoba karo request e upload korbe 
                String onRequest = scanner.nextLine();

                out.writeObject(onRequest);
                out.flush();

                if(onRequest.equalsIgnoreCase("yes")){
                  
                    System.out.println("\nEnter Request ID to upload : \n");
                    String requestID = scanner.nextLine();
                    out.writeObject(requestID);
                    out.flush();
                    System.out.println("\nEnter file path to upload: \n");
                    String filePath = scanner.nextLine();
                    File file = new File(filePath);
                    if(!file.exists() || !file.isFile()) {
                        System.out.println("\nFile does not exist. Try again.\n");
                        continue;
                    }


                    String fileName = file.getName();
                    long fileSize = file.length();

                    
                    //ebar server ke pathabo

                    out.writeObject(fileName);
                    out.writeLong(fileSize);
                    out.writeObject("Public");    //privacy auto public set korte hobe for on request
                    out.flush();  
                    String uploadStatus = (String) in.readObject(); // sevrver ke filesize pathaye dekhte hbe adou upload kora jabe kina ... buffer size theke exceed kore gele reject korbe
                    if(uploadStatus.equalsIgnoreCase("Reject")){
                        System.out.println("Upload rejected.");
                        continue;

                    }
                    //upload accepted hole server theke fileID ar chunk size nibo
                    String fileID = (String) in.readObject();
                    int chunkSize = in.readInt();

                    System.out.println("\nUpload Accepted.");
                    System.out.println("File ID: " + fileID);
                    System.out.println("Chunk Size: " + chunkSize);
                    System.out.println("Privacy: " + "Public\n");

                    FileInputStream fis = new FileInputStream(file);
                    long sent = 0;
                // int loopcount = 0;
                    //ebare file pathabo server e chunk by chunk
                    while(sent < fileSize) {
                        int toSend = (int)Math.min(chunkSize, fileSize - sent); // kokhoni chunksize er cheye bor chunk pathabo na ... pathate gele corrupt .. so for security ... chunksize ar baki size er modhye je choto ta nibo
                                                                                // ete kore ekdom last e jodi unsent bytes chunksizze theke chot hoy sheta jabe .. extra kisu pura chunk jabe na 
                        byte[] buffer = fis.readNBytes(toSend);         // file theke tosend size er bytes porbo
                        out.write(buffer);                              // bufffer e lekha bytes gulo server e pathabo
                        out.flush();

                        String ack = (String) in.readObject();          // server theke acknwoledgement nibo je chunk ta peyeche
                        if(ack.startsWith("Chunk no : ")) {
                            System.out.println(ack);
                        }
                        else{
                            System.out.println("Chunk is not acknowledged !!!");
                        }
                        sent += toSend;                                 // sent e tosend size ta add kore dibo

                    }

                    fis.close();





                    String done = (String) in.readObject();         // server theke upload complete er message nibo
                    System.out.println(done);

                }

                else {

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
                    System.out.println("\nUpload Accepted.");
                    System.out.println("File ID: " + fileID);
                    System.out.println("Chunk Size: " + chunkSize);
                    System.out.println("Privacy: " + privacy+ "\n");

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

            }

            if(command.equalsIgnoreCase("download")){
                //ONNO CLIENT ER PUBLIC FILE DOWNLOAD KORBO
                
                //age public file gula show korbo with their id and input dite bolbo user ke je konta download korte chay

                String publicFiles = (String) in.readObject();
                System.out.println("\nPublic Files: \n" + publicFiles);
                String privateFiles = (String) in.readObject();
                System.out.println("\nYour Files: \n" + privateFiles);

                System.out.println("\nEnter File ID to download: \n");
                String fileID = scanner.nextLine();

                out.writeObject(fileID);            //file id server e pathalam
                out.flush();
                String response = (String) in.readObject();         //server bolbe file pawa gese kina
                if(response.equalsIgnoreCase("File Not Found")){
                    System.out.println("File not found on server. Try again.");
                    continue;
                }


                String fileName = (String) in.readObject();       //file name ar size nibo server theke
                long fileSize = in.readLong();
                int chunkSize = in.readInt();

                File downloadTo = new File("DownloadedFiles/"+ UserName);

                downloadTo.mkdirs();

                File outputFile = new File(downloadTo, fileName);
                FileOutputStream fos = new FileOutputStream(outputFile);    

                long received = 0;


                while(received < fileSize){
                    //download chunk by chunk
                    int bytesToRead = (int)Math.min(chunkSize, fileSize - received);
                    byte[] buffer = new byte[bytesToRead];  //ekhon ei size er byte array banalam
                    in.readFully(buffer);                  //in readfully diye buffer e bytesToRead size er bytes gulo read korlam

                    fos.write(buffer, 0, bytesToRead);  //output file e bufffer write korlam
                    received += bytesToRead;          //received e bytesToRead add kore dilam
                }
                
                fos.close();

                System.out.println("\nFile " + fileName + " downloaded successfully.\n");
            }


            if(command.equalsIgnoreCase("Look up own files")){ //nijer file gula dekhbo
                String ownFiles =(String) in.readObject();                                       
                System.out.println("\nYour Files: \n" + ownFiles);


            }

            if(command.equalsIgnoreCase("Look up user files")){ //specific user er file dekhbo
                System.out.println("\nEnter username to look up: ");
                String lookupUser = scanner.nextLine();
                out.writeObject(lookupUser);
                out.flush();

                String userFiles = (String) in.readObject();
                System.out.println("Files of " + lookupUser + ":\n" + userFiles);
            }

            if(command.equalsIgnoreCase("Look up all public files")){
                //shobar shob public files dekhbo
                String allPublicFiles = (String) in.readObject();
                System.out.println("\nAll Public Files: \n" + allPublicFiles);
                

            }

            if(command.equalsIgnoreCase("Look up client list")){

                String clientList = (String) in.readObject();
                System.out.println("\nClient List: \n" + clientList);
            }

            if(command.equalsIgnoreCase("View Unread Messages")){

                System.out.println("\nYour Unread Messages: \n");
                int inboxSize = in.readInt();
                if(inboxSize == 0) {          //inbox array er size 0 mane kono message ashe nai ekhno obi
                    System.out.println("\nNo unread messages.\n");
                } else {
                    for(int i = 0; i < inboxSize; i++) {
                        String message = (String) in.readObject();       //message gulo ek ek kore nibo
                        System.out.println((i + 1) + ". " + message);
                    }
                }
            } 

            if(command.equalsIgnoreCase("Upload on request")){

                System.out.println("\nEnter a short description of the file you want to request: \n");
                String description = scanner.nextLine();
                out.writeObject(description);
                System.out.println("\nFile Request Sent To All or Specific User?[ALL/USER_NAME]\n"); //message ki ekjon ke dbo naki shobaike
                String choice = scanner.nextLine();
                out.writeObject(choice); 
                out.flush();

                String response = (String) in.readObject();       //server theke response nibo je request ta send hoise kina
                System.out.println(response);
            }
            

        }

         
    }
        }
    }
    }

