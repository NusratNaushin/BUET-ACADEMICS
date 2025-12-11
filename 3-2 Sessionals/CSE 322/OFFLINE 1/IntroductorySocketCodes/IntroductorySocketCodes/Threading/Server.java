package Threading;
import java.io.File;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.HashSet;
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
        int chunkSize;
        long uploadBytes = 0;
    }
    public static HashMap<String, FileData> fileSet = new HashMap<>();
    public static int MIN_CHUNK_SIZE = 1024;
    public static int MAX_CHUNK_SIZE = 4096;       
    public static int MAX_BUFFER_SIZE = 65536;
    public static int usedBufferSize = 0;
    public static ArrayList<String> userSet = new ArrayList<>();
    public static ArrayList<String> userHistorySet = new ArrayList  <>();


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
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        ServerSocket welcomeSocket = new ServerSocket(6666);
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
