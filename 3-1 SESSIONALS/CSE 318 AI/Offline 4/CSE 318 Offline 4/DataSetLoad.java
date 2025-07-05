import java.io.*;
import java.util.*;

public class DataSetLoad {
    public static List<AttributeLabel> loadDataSet(String filepath) {
        List<AttributeLabel> dataset = new ArrayList<>();
        String[] adultHeader = null;
        String[] irisHeader = null;
        String line;

        try (BufferedReader br = new BufferedReader(new FileReader(filepath))) {

            if (filepath.startsWith("Datasets/adult")) {
                // Hardcoded header
                adultHeader = new String[] { "age", "workclass", "digits1", "education", "digits2",
                        "marital-status", "occupation", "relationship-status", "Ethnicity", "Gender",
                        "digits3", "digits4", "digits5", "Country", "Salary Range" };
                AttributeLabel.setHeaderNames(adultHeader);

            }

            else if (filepath.startsWith("Datasets/Iris")) {
                String headerLine = br.readLine();
                String[] irisHeader1 = headerLine.split(",");

                List<String> irisHeader2 = new ArrayList<>();
                for (String col : irisHeader1) {
                    if (!col.equalsIgnoreCase("Id")) {
                        irisHeader2.add(col.trim());
                    }
                }
                AttributeLabel.setHeaderNames(irisHeader2.toArray(new String[0]));

                // for (String header : irisHeader) {
                //     // System.out.println("here");
                //     System.out.println("Header: " + header);
                // }
            }

            while ((line = br.readLine()) != null) {
                if (line.isBlank())
                    continue;
                String[] parts = line.split(",");
                List<String> row = new ArrayList<>();
                for (String part : parts) {
                    row.add(part.trim());
                }

                for (int i = 0; i < parts.length; i++) {
                    parts[i] = parts[i].trim();
                }
                Map<String, String> attributeMap = new HashMap<>();
                for (int i = 1; i < parts.length - 1; i++) {
                    attributeMap.put(AttributeLabel.headerNames[i], parts[i]);
                }
                String label = parts[parts.length - 1].trim();
                dataset.add(new AttributeLabel(attributeMap, label));

                // System.out.println(dataset.get(dataset.size() - 1).label);
            }

            // if (adultHeader != null) {
            // AttributeLabel.setHeaderNames(adultHeader);
            // } else if (irisHeader != null) {
            // AttributeLabel.setHeaderNames(irisHeader);
            // }

        } catch (IOException e) {
            e.printStackTrace();
        }
       // System.out.println("Loading complete");

        return dataset;
    }
}
