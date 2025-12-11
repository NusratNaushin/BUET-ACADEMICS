package Threading;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.Date;
import java.util.Random;
public class Worker extends Thread {
    private Socket socket;
    private ObjectOutputStream out;
    private ObjectInputStream in;
    private String username;
    private int filecount = 0;

    public Worker(Socket socket, ObjectInputStream in, ObjectOutputStream out, String username) {
        this.socket = socket;
        this.in = in;
        this.out = out;
        this.username = username;
    }

    public void run() {
        
        try {


            
            File userDir = new File("User/" + username);
            boolean created = userDir.mkdirs();
            out.writeObject("Hello " + username);
            out.writeBoolean(created);
            out.flush();

            
            while(true) {
                //client er pathano command read kori

                String command = (String) in.readObject();
                System.out.println("Command from " + username + ": " + command);

                if(command.equalsIgnoreCase("send list")) {
                    StringBuilder userList = new StringBuilder();
                    synchronized(Server.userHistorySet) {
                        for(String user : Server.userHistorySet) {
                            if(Server.userSet.contains(user)) {
                                userList.append(user).append(" Online!\n");
                            } else {
                                userList.append(user).append(" Offline\n");
                            }
                        }
                    }
                    out.writeObject(userList.toString());
                    out.flush();
                }

                if(command.equalsIgnoreCase("log out")){
                    out.writeObject("Logged Out!");
                    out.flush();
                    System.out.println(username + " logged out.");
                    break;
                }

                if(command.equalsIgnoreCase("upload")){
                    // client theke file name size receive
                    String fileName = (String) in.readObject();
                    long fileSize = in.readLong();


                    
                    //check dewa lagbe buffer size exceed kore kina
                    
                    synchronized(Server.class) {
                        if(Server.usedBufferSize + fileSize > Server.MAX_BUFFER_SIZE) {
                            out.writeObject("Reject");
                            out.flush();
                            continue;
                        } 
                            int chunksize = (int)(Math.random() * (Server.MAX_CHUNK_SIZE - Server.MIN_CHUNK_SIZE + 1)) + Server.MIN_CHUNK_SIZE;


                            String fileID = username + "_FILE_" + (++filecount);

                            Server.FileData fd = new Server.FileData();

                                fd.fileName = fileName;
                                fd.fileSize = fileSize;
                                fd.uploader = username;
                                fd.chunkSize = chunksize;
                                fd.privacy = (String) in.readObject();
                                Server.fileSet.put(fileID, fd);


                                out.writeObject("Accept");
                                out.writeObject(fileID);
                                out.writeInt(chunksize);
                                out.flush();

                                File uploadToPath = new File("User/" + username + "/" + fileName);
                                FileOutputStream fos = new FileOutputStream(uploadToPath);


                                long received = 0;

                                int loopcount = 0;
                                while(received < fileSize){
                                    int bytesToRead = (int)Math.min(chunksize, fileSize - received);
                                    byte[] buffer = new byte[bytesToRead];
                                    in.readFully(buffer);


                                    fos.write(buffer, 0, bytesToRead);
                                    received += bytesToRead;
                                    fd.uploadBytes = received;

                                    out.writeObject("Chunk no : "+ (++loopcount)+" Acknowledged!");
                                    out.flush();
                                    
                                }

                                fos.close();
                                out.writeObject("Upload Done");
                                out.flush();

                                System.out.println("File " + fileName + " uploaded from " + username);

                            


                            Server.usedBufferSize += fileSize;
                            
                    
                    }
                }
                
            }
        } catch(Exception e) {
            System.out.println(username + " disconnected.");
        }

        finally{
            synchronized(Server.userSet) {
                Server.userSet.remove(username);
            }

            try {
                socket.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
                // read messages from this client

                
            // out.writeObject("Enter Username: ");
            // username = (String) in.readObject();
            
            // File userDir = new File("User/" + username);
            // boolean created = userDir.mkdirs();
            // out.writeObject(created);
                // respond
                // out.writeObject("Server received: " + msg);
                // out.flush();