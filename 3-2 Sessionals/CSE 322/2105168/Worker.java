package OFFLINE_2105168;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.io.FileInputStream;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;

public class Worker extends Thread {
    private Socket socket;
    private ObjectOutputStream out;
    private ObjectInputStream in;
    private String username;
    private int filecount = 0;
    private int requestcount = 0;

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

            while (true) {
                // client er pathano command read kori

                String command = (String) in.readObject();
                System.out.println("Command from " + username + ": " + command);

                if (command.equalsIgnoreCase("send list")) {
                    StringBuilder userList = new StringBuilder();
                    synchronized (Server.userHistorySet) {    //ejabot joto user ache tader shobaike traverse korbo
                        for (String user : Server.userHistorySet) {
                            if (Server.userSet.contains(user)) {
                                userList.append(user).append(" Online!\n");
                            } else {
                                userList.append(user).append(" Offline\n");
                            }
                        }
                    }
                    out.writeObject(userList.toString());
                    out.flush();
                }

                if (command.equalsIgnoreCase("log out")) {
                    out.writeObject("Logged Out!");
                    out.flush();
                    System.out.println(username + " logged out.");
                    break;
                }

                if (command.equalsIgnoreCase("upload")) {
                    // client theke file name size receive
                    String onRequest = (String) in.readObject();

                    if (onRequest.equalsIgnoreCase("yes")) {

                        String requestID = (String) in.readObject();

                        String fileName = (String) in.readObject();
                        long fileSize = in.readLong();
                        String requestOwner = requestID.split("_REQ_")[0];            //requ id theke owner ke extract krolam
                        System.out.println("DEBUG: " + requestOwner);
                        File logFile = new File("User/" + requestOwner + "/log.txt");   //log file banbooooooo for history

                        FileOutputStream logFos = new FileOutputStream(logFile, true);
                        DateTimeFormatter fmt = DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm:ss");
                        String time = LocalDateTime.now().format(fmt);
                        // check dewa lagbe buffer size exceed kore kina

                        synchronized (Server.class) {
                            if (Server.usedBufferSize + fileSize > Server.MAX_BUFFER_SIZE) {
                                out.writeObject("Reject");
                                out.flush();
                                String logEntry = fileName + " upload failed at " + time + " Status: Rejected\n";       
                                logFos.write(logEntry.getBytes());
                                logFos.close();

                                continue;
                            }
                            int chunksize = (int) (Math.random() * (Server.MAX_CHUNK_SIZE - Server.MIN_CHUNK_SIZE + 1))
                                    + Server.MIN_CHUNK_SIZE;              // math random 0 theke 11 er moddhe value dey so amra to chai min theke max er moddhe erjonne max-min kore range ber kore sheta diye gun dilam
                                                                         //  ekhn shudhu eta rakhle 0 theke range obdi random nto but amra cahi min theke range er moddhe nik erjonne abar ei value ke min diye jog kore dilam

                            String fileID = requestOwner + "_FILE_" + (++filecount);

                            Server.FileData fd = new Server.FileData();

                            fd.fileName = fileName;
                            fd.fileSize = fileSize;
                            fd.uploader = username;
                            fd.owner = requestOwner;
                            fd.chunkSize = chunksize;
                            fd.privacy = (String) in.readObject();
                            Server.fileSet.put(fileID, fd);         //fileset e file er data gula rakhbo pore jokhon look up korboei set kaaje lagabo

                            out.writeObject("Accept");
                            out.writeObject(fileID);
                            out.writeInt(chunksize);
                            out.flush();

                            File uploadToPath = new File("User/" + requestOwner + "/" + fileName);
                            FileOutputStream fos = new FileOutputStream(uploadToPath);

                            long received = 0;

                            int loopcount = 0;
                            while (received < fileSize) {
                                int bytesToRead = (int) Math.min(chunksize, fileSize - received);    // kokhoni chunksize er cheye bor chunk pathabo na ... pathate gele corrupt .. so for security ... chunksize ar baki size er modhye je choto ta nibo
                                                                                // ete kore ekdom last e jodi unsent bytes chunksizze theke chot hoy sheta jabe .. extra kisu pura chunk jabe na 
                                byte[] buffer = new byte[bytesToRead];
                                in.readFully(buffer);

                                fos.write(buffer, 0, bytesToRead); 
                                received += bytesToRead;
                                fd.uploadBytes = received;

                                out.writeObject("Chunk no : " + (++loopcount) + " Acknowledged!");
                                out.flush();

                            }

                            fos.close();
                            out.writeObject("Upload Done");
                            out.flush();

                            System.out.println("File " + fileName + " uploaded from " + username);

                            Server.usedBufferSize += fileSize;

                            // upload er log file rakhbo

                            // the filename, date and time, upload or download action,and status (successful
                            // or failed)
                            String logEntry = fileName + " uploaded at " + time + " Status: Successful\n";
                            logFos.write(logEntry.getBytes());   // file to ar string bojhe na tai byte e rupantor kore dbo
                            logFos.close();

                        }

                        //ar jehetu on request upload tai jonne inbox e notify kore dibo je upload complete hoye geche
                        ArrayList<String>inbox = Server.Inbox().get(requestOwner);

                        if(inbox == null){
                            inbox = new ArrayList<>();
                        }

                        String notify_client = "Your request (Request ID: " + requestID + ") has been fulfilled. File Name: " + fileName + " Uploaded by: " + username;


                        inbox.add(notify_client);
                        Server.Inbox().put(requestOwner, inbox);


                    } else {
                        String fileName = (String) in.readObject();
                        long fileSize = in.readLong();

                        File logFile = new File("User/" + username + "/log.txt");

                        FileOutputStream logFos = new FileOutputStream(logFile, true);
                        DateTimeFormatter fmt = DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm:ss");
                        String time = LocalDateTime.now().format(fmt);
                        // check dewa lagbe buffer size exceed kore kina

                        synchronized (Server.class) {
                            if (Server.usedBufferSize + fileSize > Server.MAX_BUFFER_SIZE) {  //jotokhani buffer used and file er size er jogfol jodi max size ke exceed kore tahole reject
                                out.writeObject("Reject");
                                out.flush();
                                String logEntry = fileName + " upload failed at " + time + " Status: Rejected\n";
                                logFos.write(logEntry.getBytes());
                                logFos.close();

                                continue;
                            }
                            int chunksize = (int) (Math.random() * (Server.MAX_CHUNK_SIZE - Server.MIN_CHUNK_SIZE + 1))
                                    + Server.MIN_CHUNK_SIZE;

                            String fileID = username + "_FILE_" + (++filecount);

                            Server.FileData fd = new Server.FileData();

                            fd.fileName = fileName;
                            fd.fileSize = fileSize;
                            fd.uploader = username;
                            fd.owner = username;
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
                            while (received < fileSize) {
                                int bytesToRead = (int) Math.min(chunksize, fileSize - received);
                                byte[] buffer = new byte[bytesToRead];
                                in.readFully(buffer);

                                fos.write(buffer, 0, bytesToRead);
                                received += bytesToRead;
                                fd.uploadBytes = received;

                                out.writeObject("Chunk no : " + (++loopcount) + " Acknowledged!");
                                out.flush();

                            }

                            fos.close();
                            out.writeObject("Upload Done");
                            out.flush();

                            System.out.println("File " + fileName + " uploaded from " + username);

                            Server.usedBufferSize += fileSize;

                            // upload er log file rakhbo

                            // the filename, date and time, upload or download action,and status (successful
                            // or failed)
                            String logEntry = fileName + " uploaded at " + time + " Status: Successful\n";
                            logFos.write(logEntry.getBytes());
                            logFos.close();

                        }
                    }
                }

                if (command.equalsIgnoreCase("download")) {

                    // file public kina check dte hbe then list pathabo public gular
                    // ar nijer file private hok ba public download korte parbe so nijer files o
                    // dekhabo jodi thake kichu

                    StringBuilder publicFileList = new StringBuilder();
                    StringBuilder privateFileList = new StringBuilder();
                    for (String id : Server.fileSet.keySet()) {
                        Server.FileData fd = Server.fileSet.get(id);
                        if (fd.privacy.equalsIgnoreCase("public")) {
                            publicFileList.append(id).append(" : ").append(fd.fileName).append("\n");
                        }
                        if (fd.uploader.equals(username)) {
                            privateFileList.append(id).append(" : ").append(fd.fileName).append(" (").append(fd.privacy)
                                    .append(")\n");
                        }
                    }
                    out.writeObject(publicFileList.toString());
                    out.writeObject(privateFileList.toString());
                    out.flush();

                    String fileId = (String) in.readObject();

                    File logFile = new File("User/" + username + "/log.txt");

                    FileOutputStream logFos = new FileOutputStream(logFile, true);
                    DateTimeFormatter fmt = DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm:ss");
                    String time = LocalDateTime.now().format(fmt);

                    if (!Server.fileSet.containsKey(fileId)) {   //fileid khuje na paile fail
                        out.writeObject("File Not Found");
                        out.flush();
                        // Server.FileData fd = Server.fileSet.get(fileId);

                        String logEntry = fileId + " download failed at " + time + " Status: Rejected\n";
                        logFos.write(logEntry.getBytes());
                        logFos.close();
                        continue;
                    }

                    Server.FileData fd = Server.fileSet.get(fileId);
                    if (fd.privacy.equals("private") && !fd.uploader.equals(username)) {
                        out.writeObject("Access Denied");
                        out.flush();
                        continue;
                    }

                    out.writeObject("Ready");
                    out.writeObject(fd.fileName);
                    out.writeLong(fd.fileSize);
                    out.writeInt(fd.chunkSize); // maxChunkSize hobe ki ?
                    out.flush();

                    File fileToSendFromSeverSideToDownload = new File("User/" + fd.uploader + "/" + fd.fileName);
                    FileInputStream fis = new FileInputStream(fileToSendFromSeverSideToDownload);

                    long sent = 0;

                    while (sent < fd.fileSize) {

                        int toSend = (int) Math.min(fd.chunkSize, fd.fileSize - sent);

                        byte[] buffer = fis.readNBytes(toSend);
                        out.write(buffer);
                        out.flush();
                        sent += toSend;
                    }
                    

                    fis.close();
                    String logEntry = fd.fileName + " downloaded at " + time + " Status: Successful\n";
                    logFos.write(logEntry.getBytes());
                    logFos.close();

                    System.out.println("File " + fd.fileName + " downloaded by " + username);
                    out.flush();

                    Server.usedBufferSize -=fd.fileSize;

                }

                if (command.equalsIgnoreCase("Look up own files")) {          
                    StringBuilder privateFileList = new StringBuilder();
                    for (String id : Server.fileSet.keySet()) {
                        Server.FileData fd = Server.fileSet.get(id);
                        if (fd.uploader.equals(username) || fd.owner.equals(username)) {    //upload duibhabe hoy so uploader othoba requ owner naam diye khujte hbe list
                            privateFileList.append(id).append(" : ").append(fd.fileName).append(" (").append(fd.privacy)
                                    .append(")\n");
                        }
                    }
                    out.writeObject(privateFileList.toString());
                    out.flush();

                }

                if (command.equalsIgnoreCase("Look up user files")) {

                    String lookupUser = (String) in.readObject();

                    StringBuilder userFileList = new StringBuilder();
                    for (String id : Server.fileSet.keySet()) {
                        Server.FileData fd = Server.fileSet.get(id);
                        if (fd.uploader.equals(lookupUser) && fd.privacy.equals("public")) {   //uer er file publicholie dekha jabe
                            userFileList.append(id).append(" : ").append(fd.fileName).append("\n");
                        }
                    }
                    out.writeObject(userFileList.toString());
                    out.flush();
                }

                if (command.equalsIgnoreCase("Look up all public files")) {

                    StringBuilder allFiles = new StringBuilder();
                    for (String id : Server.fileSet.keySet()) {  
                        Server.FileData fd = Server.fileSet.get(id);
                        if (fd.privacy.equals("public")) {
                            allFiles.append(id).append(" : ").append(fd.fileName).append(" (Uploaded by: ")
                                    .append(fd.uploader).append(")\n");
                        }
                    }

                    out.writeObject(allFiles.toString());
                    out.flush();

                }
                if (command.equalsIgnoreCase("Look up client list")) {
                    StringBuilder userList = new StringBuilder();
                    synchronized (Server.userHistorySet) {
                        for (String user : Server.userHistorySet) {
                            if (Server.userSet.contains(user)) {
                                userList.append(user).append(" Online!\n");
                            } else {
                                userList.append(user).append(" Offline\n");
                            }
                        }
                    }
                    out.writeObject(userList.toString());
                    out.flush();

                }

                if (command.equalsIgnoreCase("View Unread Messages")) {

                    ArrayList<String> inbox = Server.Inbox().get(username);   //jei user taar inbox ta niye ashbo 

                    System.out.println("debug ");
                    out.writeInt(Server.getInboxSize(username));

                    if (Server.getInboxSize(username) == 0) {
                        out.flush();
                    } else {
                        for (String message : inbox) { //inbx e thaka shob message porbo
                            out.writeObject(message);   
                        }
                        out.flush();
                        inbox.clear(); // message gulo to read hoye geche tai unread msg clear korlam arki

                    }
                }

                if (command.equalsIgnoreCase("Upload on request")) {

                    String description = (String) in.readObject();
                    requestcount++;

                    String requestID = username + "_REQ_" + requestcount;
                    Server.GetFileRequest().put(requestID, description);

                    String choice = in.readObject().toString();

                    if (Server.userHistorySet.size() == 0) {
                        out.writeObject("No other users available to send the request.");
                        out.flush();
                        continue;
                    }

                    else {
                        if (choice.equalsIgnoreCase("ALL")) {

                            for (int i = 0; i < Server.userHistorySet.size(); i++) {
                                String user = Server.userHistorySet.get(i);
                                if (!user.equals(username)) {

                                    ArrayList<String> message = Server.Inbox().get(user);
                                    if(message == null){
                                        message = new ArrayList<>();
                                    }
                                    message.add("Reques ID: " + requestID + " Description: " + description
                                            + " (Sent by: " + username + ")");
                                    Server.Inbox().put(user, message);    //request er message ta all user inbox e put korbo
                                }
                            }
                            out.writeObject("File request sent to all users.");
                            out.flush();
                        }

                        else {
                            String specificUser = choice;
                            if (!Server.userHistorySet.contains(specificUser)) {
                                out.writeObject("User not found. Request not sent.");
                                out.flush();
                                continue;
                            } else {
                                ArrayList<String> message = Server.Inbox().get(specificUser);         // speciific user ke msg dbo
                                if(message == null){
                                    message = new ArrayList<>();
                                }
                                message.add("Reques ID: " + requestID + " Description: " + description + " (Sent by: "
                                        + username + ")");
                                Server.Inbox().put(specificUser, message);

                                out.writeObject("File request sent to " + specificUser);
                                out.flush();
                            }
                        }
                    }


                }

            }
        } catch (Exception e) {
            System.out.println(username + " disconnected.");
        }

        finally {
            synchronized (Server.userSet) {
                Server.userSet.remove(username);  //user offline hoy gele userset theke shoraye dbo
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