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

        Scanner scanner = new Scanner(System.in);
            
                System.out.println("Enter User Name");
                String UserName = scanner.nextLine();
                out.writeObject(UserName);
                out.flush();

                String msg = (String) in.readObject();
                System.out.println(msg);
                
                if(msg.equals("Username already taken. Connection closing.")) {
                    System.out.println("USername already in use!!!");
                    socket.close();
                    return;
                }   
                
                boolean created = in.readBoolean();

                if(created) {
                    System.out.println("Directory created");
                } else {
                    System.out.println("Directory already exists");
        }

        
        
        System.out.println("Login Successful");
        while (true) {

            //user command dibe client theke
            System.out.println("Enter Command: ");
            String command = scanner.nextLine();

            //ebare etake server e pathacchi
            out.writeObject(command);
            out.flush();

            if(command.equalsIgnoreCase("Send list")){
                String userList = (String) in.readObject();
                System.out.println("User List: \n" + userList);
            }

            if(command.equalsIgnoreCase("log out")){
                String logoutMsg = (String) in.readObject();
                System.out.println(logoutMsg);
                System.out.println("Connection closing...");
                break;
            }

        }
    }
}
