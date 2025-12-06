package Threading;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        Socket socket = new Socket("localhost", 6666);
        System.out.println("Connection established");
        System.out.println("Remote port: " + socket.getPort());
        System.out.println("Local port: " + socket.getLocalPort());

        // buffers
        ObjectOutputStream out = new ObjectOutputStream(socket.getOutputStream());
        ObjectInputStream in = new ObjectInputStream(socket.getInputStream());

        try (

            Scanner scanner = new Scanner(System.in)) {
            while (true) {
                System.out.println("Enter User Name");
                String UserName = scanner.nextLine();
                out.writeObject(UserName);
                out.flush();

                String msg = (String) in.readObject();
                System.out.println(msg);

            }
        }

    }
}
