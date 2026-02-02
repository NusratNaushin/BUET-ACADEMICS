import java.io.File;

public class ClearServer {

    public static void deleteDirectory(File file)
    {
        // store all the paths of files and folders present
        // inside directory
        for (File subfile : file.listFiles()) {

            // if it is a subfolder
            // recursiley call function to empty subfolder
            if (subfile.isDirectory()) {
                deleteDirectory(subfile);
            }

            // delete files and empty subfolders
            subfile.delete();
        }
    }

    public static void main(String[] args){
        File file = new File("FileServer");
        deleteDirectory(file);

        file = new File("Downloads");
        deleteDirectory(file);
    }
}
