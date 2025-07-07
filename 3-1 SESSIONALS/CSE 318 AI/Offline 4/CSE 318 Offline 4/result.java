import java.io.FileWriter;
import java.io.IOException;

public class result{

    public static void log(String datasetName, String criterion, int maxDepth,
                           double avgAccuracy, double avgNodeCount, double avgUnprunedDepth) {

        try (FileWriter writer = new FileWriter("results.csv", true)) {
            if (maxDepth == 0) {
                writer.write(String.format("%s,%s,%d,%.2f,%.0f,%.0f\n",
                        datasetName, criterion.toUpperCase(), maxDepth,
                        avgAccuracy * 100, avgNodeCount, avgUnprunedDepth));
            } else {
                writer.write(String.format("%s,%s,%d,%.2f,%.0f,%d\n",
                        datasetName, criterion.toUpperCase(), maxDepth,
                        avgAccuracy * 100, avgNodeCount, maxDepth));
            }
        } catch (IOException e) {
            System.err.println("Could not write to CSV: " + e.getMessage());
        }
    }

    public static String getDatasetName(String path) {
        if (path.toLowerCase().contains("iris")) return "Iris";
        if (path.toLowerCase().contains("adult")) return "Adult";
        return "Unknown";
    }
}
