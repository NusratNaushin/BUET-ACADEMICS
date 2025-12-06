package Threading;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.Date;

public class Worker extends Thread {
    private Socket socket;
    private ObjectOutputStream out;
    private ObjectInputStream in;
    private String username;

    public Worker(Socket socket, ObjectInputStream in, ObjectOutputStream out, String username) {
        this.socket = socket;
        this.in = in;
        this.out = out;
        this.username = username;
    }

    public void run() {
        try {
            while(true) {
                // read messages from this client
                String msg = (String) in.readObject();
                System.out.println(username + " says: " + msg);

                // respond
                out.writeObject("Server received: " + msg);
                out.flush();
            }
        } catch(Exception e) {
            System.out.println(username + " disconnected.");
        }
    }
}
