package Threading;
import java.io.File;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketAddress;
import java.util.*;
import java.io.IOException;

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

            // open thread
            Thread worker = new Worker(socket);
            worker.start();


        }

    }
}
