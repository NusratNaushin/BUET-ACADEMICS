package OFFLINE_2105168;
import java.net.ServerSocket;
import java.net.Socket;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.HashMap;   

public class Server {


    public static class FileData {
    
        String fileName;
        long fileSize;
        String uploader;
        String owner;
        int chunkSize;
        long uploadBytes = 0;
        String privacy;
    }
    public static HashMap<String, FileData> fileSet = new HashMap<>();
    public static int MIN_CHUNK_SIZE = 1024;
    public static int MAX_CHUNK_SIZE = 4096;       
    public static int MAX_BUFFER_SIZE = 65536;
    public static int usedBufferSize = 0;
    public static ArrayList<String> userSet = new ArrayList<>();            // ekhon jara online
    public static ArrayList<String> userHistorySet = new ArrayList  <>();   //ejabot online offline jara connect hoise shobai
    public static HashMap<String , ArrayList<String>> inbox = new HashMap<>();
    public static HashMap<String , String > FileRequest = new HashMap<>();


    public static int getMAX_BUFFER_SIZE() {
        return MAX_BUFFER_SIZE;
    }

    public static int getMAX_CHUNK_SIZE() {
        return MAX_CHUNK_SIZE;
    }
    public static int getMIN_CHUNK_SIZE() {
        return MIN_CHUNK_SIZE;
    }

    public static int getUsedBufferSize() {
        return usedBufferSize;
    }

    public static ArrayList<String> getUserHistorySet() {
        return userHistorySet;
    }
    public static ArrayList<String> getUserSet() {
        return userSet;
    }

    public static HashMap<String , ArrayList<String>> Inbox(){


        return inbox;
    }

    public static int getInboxSize(String username){
        if(inbox.containsKey(username)){
            return inbox.get(username).size();
        }
        return 0;
    }
    public static HashMap<String , String > GetFileRequest(){
        return FileRequest;
    }
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        try (ServerSocket welcomeSocket = new ServerSocket(6666)) {
            while(true) {
                System.out.println("Waiting for connection...");
                Socket socket = welcomeSocket.accept();
                System.out.println("Connection established");

                

                ObjectOutputStream out = new ObjectOutputStream(socket.getOutputStream());
                out.flush();
                ObjectInputStream in = new ObjectInputStream(socket.getInputStream());

                String username = (String) in.readObject();
                System.out.println("Client says: " + username   ); 
                
                synchronized(userSet) {
                    if(userSet.contains(username)) {
                        out.writeObject("Username already taken. Connection closing.");
                        out.flush();
                        socket.close();
                        continue;
                    } else {
                        userSet.add(username);
                        
                        inbox.put(username, new ArrayList<>());
                    }
                }

                synchronized(userHistorySet) {
                    userHistorySet.add(username);
                }

                // File userDir = new File("User/" + username);
                // boolean created = userDir.mkdirs();
                // out.writeObject("Hello " + username);
                // out.writeBoolean(created);
                // out.flush();

                // open thread



                Thread worker = new Worker(socket, in, out, username);
                worker.start();


            }
        }

    }
}
