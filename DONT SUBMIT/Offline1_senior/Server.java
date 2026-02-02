import java.io.File;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketAddress;
import java.util.*;

public class Server {
    private static HashMap<String, SocketAddress> Students;
    private static HashMap<Integer, String> files;
    private static int file_id = 0;
    private static ArrayList<Request> requests = new ArrayList<Request>();
    private static int request_id = 0;
    private static long MAX_BUFFER_SIZE = 100000;
    private static int MIN_CHUNK_SIZE = 1000;
    private static int MAX_CHUNK_SIZE = 10000;
    private static long buffer = 0;

    public static boolean checkBuffer(long filesize){
        if( buffer + filesize > MAX_BUFFER_SIZE ) return false;
        buffer += filesize;
        System.out.println("Buffer occupied : " + buffer + " bytes");
        return true;
    }

    public static void clearBuffer(long filesize){
        buffer -= filesize;
        System.out.println("Buffer occupied : " + buffer + " bytes");

    }

    public static int get_random_chunk_size(){
        return (int)(Math.random()*(MAX_CHUNK_SIZE - MIN_CHUNK_SIZE + 1) + MIN_CHUNK_SIZE);
    }

    public static int get_max_chunk_size(){
        return MAX_CHUNK_SIZE;
    }

    public static boolean login(String student_id, SocketAddress IPAddress){
        if(Students.containsKey(student_id) == true){
            System.out.println(student_id + " is already logged in, Denying");
            return false;
        }
        Students.put(student_id, IPAddress);
        System.out.println(student_id + " has logged in with IP Address : " + IPAddress);
        String path = "FileServer/" + student_id + "/";
        File directory = new File(path);

        if (!directory.exists()) {
            directory.mkdir();
            File public_dir = new File( path + "public/");
            File private_dir = new File( path + "private/");
            public_dir.mkdir();
            private_dir.mkdir();
            System.out.println("Folder created with the name " + student_id + " in File Server");
        }
        return true;
    }

    public static void logout(String student_id){
        Students.remove(student_id);
    }

    public static ArrayList<String> get_active_users(){
        Set<String> keySet = Students.keySet();
        ArrayList<String> listOfKeys = new ArrayList<String>(keySet);
        return listOfKeys;
    }

    public static String[] get_users(){
        File directoryPath = new File("FileServer");
        //List of all files and directories
        return directoryPath.list();
    }

    public static void addRequest(String student_id, String description){
        requests.add(new Request(request_id, student_id, description));
        request_id++;
    }

    public static ArrayList<Request> getRequests(){
        return requests;
    }

    public static void addUpload( int req_id , String granter, String filepath){
        for( int i = 0 ; i < requests.size() ; i++ ){
            if(requests.get(i).getRequest_id() == req_id){
                requests.get(i).acceptRequest(granter, filepath);
                break;
            }
        }
    }

    public static void removeRequest(int request_id){
        for( int i = 0 ; i < requests.size() ; i++ ){
            if(requests.get(i).getRequest_id() == request_id){
                requests.remove(i);
                break;
            }
        }
    }

    public static boolean check_request_id(int request_id){
        for( int i = 0 ; i < requests.size() ; i++ ){
            if(requests.get(i).getRequest_id() == request_id){
                return true;
            }
        }
        return false;
    }

    public static int addFile(String filepath){
        file_id++;
        files.put(file_id, filepath);
        return file_id;
    }

    public static String get_file_path(int file_id){
        return files.get(file_id);
    }

    public static Integer get_file_id(String filepath){
        for (Map.Entry<Integer, String> entry : files.entrySet()) {
            if (entry.getValue().equals(filepath)) {
                return entry.getKey();
            }
        }
        return 0;
    }

    public static void main(String[] args) throws Exception {
        // Creating a FileServer
        String path = "FileServer/";
        File directory = new File(path);
        if (!directory.exists()) {
            directory.mkdir();
        }

        Students = new HashMap<String, SocketAddress>();
        files = new HashMap<Integer, String>();
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
