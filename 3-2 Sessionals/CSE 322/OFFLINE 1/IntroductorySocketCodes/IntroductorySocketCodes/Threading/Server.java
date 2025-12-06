package Threading;
import java.io.File;
import java.net.ServerSocket;
import java.net.Socket;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

public class Server {

    private static int MIN_CHUNK_SIZE = 1024;
    private static int MAX_CHUNK_SIZE = 4096;       
    private static int MAX_BUFFER_SIZE = 65536;

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
            System.out.println("Client says: " + username   ); // read client message

            File userDir = new File("server_storage/" + username);
            boolean created = userDir.mkdirs();
            if(created) {
                System.out.println("Directory created");
            } else {
                System.out.println("Directory already exists");
            }

            out.writeObject("Hello from server");

            // open thread
            Thread worker = new Worker(socket, in, out, username);
            worker.start();


        }

    }
}
