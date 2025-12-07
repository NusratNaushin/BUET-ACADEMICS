package Threading;
import java.io.File;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.HashSet;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

public class Server {

    private static int MIN_CHUNK_SIZE = 1024;
    private static int MAX_CHUNK_SIZE = 4096;       
    private static int MAX_BUFFER_SIZE = 65536;
    public static HashSet<String> userSet = new HashSet<>();
    public static HashSet<String> userHistorySet = new HashSet<>();


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

            

            File userDir = new File("User/" + username);
            boolean created = userDir.mkdirs();
            out.writeObject("Hello " + username);
            out.writeBoolean(created);
            out.flush();

            // open thread
            Thread worker = new Worker(socket, in, out, username);
            worker.start();


        }

    }
}
