package Threading;

import java.io.File;
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