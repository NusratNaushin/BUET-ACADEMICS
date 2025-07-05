import java.util.List;
import java.util.Map;
import java.util.ArrayList;
import java.util.HashMap;

public class DecisionTreeBuild {
    public Node root_attribute;
    public int max_depth;
    public int currentDepth = 0;
    public String attribute_selection_criteria;

    public DecisionTreeBuild(String attribute_selection_criteria, int max_depth) {
        this.root_attribute = null;
        this.max_depth = max_depth;
        this.attribute_selection_criteria = attribute_selection_criteria;
    }

    public void train(List<AttributeLabel> dataset) {
        this.root_attribute = buildTree(dataset, 0);
    }

    private Node buildTree(List<AttributeLabel> data, int depth) {

System.out.println("depth = " + depth + " / max_depth = " + max_depth + " / data size = " + data.size());

        if (data.isEmpty() || (max_depth > 0 && depth >= max_depth)) {
            System.out.println("Reached max depth or empty data at depth: " + depth);
            return new Node(true, getLabelWithMajorityFrequency(data));
        }

        String firstLabel = data.get(0).label;
        boolean isAllLabelSame = true;

        for (AttributeLabel al : data) {
            if (!al.label.equals(firstLabel)) {
                isAllLabelSame = false;
                break;
            }
        }
        if (isAllLabelSame) {

            return new Node(true, firstLabel);

        }

        int selectAttribute = chooseAttributeWithCrieterion(data);

        if (selectAttribute == -1) {
            return new Node(true, getLabelWithMajorityFrequency(data));
        }

        Node node = new Node(false, null);
        node.splitting_attribute = selectAttribute;
        node.majorityLabel = getLabelWithMajorityFrequency(data);

        Map<String, List<AttributeLabel>> groupedDataByAttributeValue = new HashMap<>();

        for (int i = 0; i < data.size(); i++) {
            AttributeLabel currentSample = data.get(i);
            String attributeValue = currentSample.attributes.get(AttributeLabel.headerNames[selectAttribute]);
            if (groupedDataByAttributeValue.containsKey(attributeValue)) {
                List<AttributeLabel> existingList = groupedDataByAttributeValue.get(attributeValue);
                existingList.add(currentSample);
            } else {
                List<AttributeLabel> newList = new ArrayList<>();
                newList.add(currentSample);
                groupedDataByAttributeValue.put(attributeValue, newList);
            }

        }

        for (Map.Entry<String, List<AttributeLabel>> entry : groupedDataByAttributeValue.entrySet()) {
            String attributeValue = entry.getKey();
            List<AttributeLabel> subsetForThatValue = entry.getValue();
            Node childNode = buildTree(subsetForThatValue, depth + 1);

            node.children_map.put(attributeValue, childNode);
        }

       // System.out.println("depth " + depth + " max depth " + max_depth);

        return node;

    }

    private int chooseAttributeWithCrieterion(List<AttributeLabel> data) {

        int bestAttribute = -1;
        double bestScore = -1;

        double score = -1;
        for (int i = 0; i < AttributeLabel.headerNames.length - 1; i++) {
            if (attribute_selection_criteria.toLowerCase().equals("ig")) {
                score = AttributeSelectionStrat.calculateIG(data, AttributeLabel.headerNames[i]);
            }

            else if (attribute_selection_criteria.toLowerCase().equals("igr")) {
                score = AttributeSelectionStrat.IGR(data, AttributeLabel.headerNames[i]);
            }

            else if (attribute_selection_criteria.toLowerCase().equals("nwig")) {
                score = AttributeSelectionStrat.NWIG(data, AttributeLabel.headerNames[i]);
            }

            if (score > bestScore) {
                bestScore = score;
                bestAttribute = i;
            }
        }
        return bestAttribute;
    }

    private String getLabelWithMajorityFrequency(List<AttributeLabel> data) {
        Map<String, Integer> labelCount = new HashMap<>();

        for (AttributeLabel al : data) {
            String label = al.label;

            if (labelCount.containsKey((label))) {
                int currentFrequency = labelCount.get(label);
                labelCount.put(label, currentFrequency + 1);
            } else {
                labelCount.put(label, 1);
            }
        }

        String majorityLabel = null;
        int maxCount = -1;

        for (Map.Entry<String, Integer> entry : labelCount.entrySet()) {
            String currentLabel = entry.getKey();
            int currentCount = entry.getValue();

            if (currentCount > maxCount) {
                maxCount = currentCount;
                majorityLabel = currentLabel;
            }
        }

      //  System.out.println("Majority Label: " + majorityLabel + " with count: " + maxCount);
        return majorityLabel;
    }

    public String predictResult(List<String> attributes) {
        Node currentNode = root_attribute;

        while (currentNode.is_leaf == false) {
            String attributeValue = attributes.get(currentNode.splitting_attribute);
            if (currentNode.children_map.containsKey(attributeValue)) {
                currentNode = currentNode.children_map.get(attributeValue);
            } else {
                return currentNode.majorityLabel;
            }
        }
        return currentNode.label;
    }

    public double calculateAccuracy(List<AttributeLabel> testData) {
        int correctPredictions = 0;

        for (AttributeLabel sample : testData) {

            List<String> attributeList = new ArrayList<>();

            for (String header : AttributeLabel.headerNames) {
                attributeList.add(sample.attributes.get(header));
            }

            String predictedLabel = predictResult(attributeList);

        //    System.out.println("Predicted: " + predictedLabel + ", Actual: " + sample.label);
            if (predictedLabel.equals(sample.label)) {
                correctPredictions++;
            }
        }

        return (double) correctPredictions / testData.size();
    }
}
