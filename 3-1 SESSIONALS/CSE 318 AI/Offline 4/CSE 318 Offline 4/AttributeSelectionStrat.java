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

    public static double calc_info_gain(List<AttributeLabel> dataset, int attributeIndex) {
        Map<String, List<AttributeLabel>> subsets = partition_by_attribute(dataset, attributeIndex);
        
        double totalEntropy = calc_entropy(dataset);
        double weightedEntropy = 0.0;
        
        for (List<AttributeLabel> subset : subsets.values()) {
            double subsetEntropy = calc_entropy(subset);
            weightedEntropy += ((double) subset.size() / dataset.size()) * subsetEntropy;
        }
        
        return totalEntropy - weightedEntropy;
    }

    public static Map<String, List<AttributeLabel>> partition_by_attribute(List<AttributeLabel> data, int attrIndex) {
        Map<String, List<AttributeLabel>> map = new HashMap<>();
        for (AttributeLabel inst : data) {
            String val = inst.attributes[attrIndex];
            map.computeIfAbsent(val, v -> new ArrayList<>()).add(inst);
        }
        return map;
    }
}
