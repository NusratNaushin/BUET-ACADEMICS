import java.util.*;


public class AttributeSelectionStrat {
    
    public static double calc_entropy(List<AttributeLabel> dataset) {
        Map<String, Integer> labelCount = new HashMap<>();
        for (AttributeLabel row : dataset) {
            labelCount.put(row.label, labelCount.getOrDefault(row.label, 0) + 1);
        }
        
        double entropy = 0.0;
        int total = dataset.size();
        
        for (int count : labelCount.values()) {
            double probability = (double) count / total;
            entropy -= probability * Math.log(probability) / Math.log(2);
        }
        
        return entropy;
    }

private static double calculateIG(List<AttributeLabel> instances, String attribute) {
    double totalEntropy = calc_entropy(instances);
    
    Map<String, List<AttributeLabel>> subsets = new HashMap<>();
    for (AttributeLabel instance : instances) {
        String value = instance.attributes.get(attribute);
        if (!subsets.containsKey(value)) {
            subsets.put(value, new ArrayList<>());
        }
        subsets.get(value).add(instance);
    }
    double splitEntropy = 0;
    int totalInstances = instances.size();

    for (List<AttributeLabel> subset : subsets.values()) {
        double weight = (double) subset.size() / totalInstances;
        splitEntropy += weight * calc_entropy(subset);
    }

    return totalEntropy - splitEntropy;
}

public static double IGR(List<AttributeLabel> instances, String attribute){

    double igr = 0.0;
     Map<String, Integer> valueCounts = new HashMap<>();
        for (AttributeLabel instance : instances) {
            String value = instance.attributes.get(attribute);
            valueCounts.put(value, valueCounts.getOrDefault(value, 0) + 1);
        }
        
        double iv = 0;
        int totalInstances = instances.size();
        
        for (int count : valueCounts.values()) {
            if (count > 0) {
                double probability = (double) count / totalInstances;
                iv -= probability * Math.log(probability) / Math.log(2);
            }
        }

        double ig = calculateIG(instances, attribute);
        if(iv == 0){
            return 0;
        }
        else{
            igr = ig/iv;
            return igr;
        }
        
}


     public static double NWIG(List<AttributeLabel> data, String attribute){

        double ig = calculateIG(data, attribute);

        double nwig = 0.0;

        Set<String> distinct_k_values = new HashSet<>();
        for (AttributeLabel instance : data) {
            String value = instance.attributes.get(attribute);
            distinct_k_values.add(value);
     }

     int k = distinct_k_values.size();
    int s = data.size();

    if (s == 0 || k == 0) {
        return 0;
    }

    double penalty = (1- (double)(k-1)/s);
    nwig = (ig/(Math.log(k+1)/Math.log(2)))*penalty;

    return nwig;






}

}