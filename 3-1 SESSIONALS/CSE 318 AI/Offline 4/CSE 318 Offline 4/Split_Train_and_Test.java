import java.util.*;
public class Split_Train_and_Test {
    public List<AttributeLabel> trainSet;
    public List<AttributeLabel> testSet;

    public Split_Train_and_Test(List<AttributeLabel> trainSet, List<AttributeLabel> testSet) {
        this.trainSet = trainSet;
        this.testSet = testSet;
    }
    
    static class SplitResult {
        public List<AttributeLabel> trainSet;
        public List<AttributeLabel> testSet;
    
        public SplitResult(List<AttributeLabel> trainSet, List<AttributeLabel> testSet) {
            this.trainSet = trainSet;
            this.testSet = testSet;
        }
    }

    
    public static SplitResult splitData(List<AttributeLabel> dataset, double trainRatio) {

        long seed = System.currentTimeMillis();
        Collections.shuffle(dataset, new Random(seed));
        int trainSize = (int) (dataset.size() * trainRatio);
        List<AttributeLabel> trainSet = new ArrayList<>(dataset.subList(0, trainSize));
        System.out.println("Train set size: " + trainSet.size());

        //train set er data print dibo
        System.out.println("Train set data:");
        for (AttributeLabel al : trainSet) {
            System.out.println(al.attributes + " -> " + al.label);
        }

        List<AttributeLabel> testSet = new ArrayList<>(dataset.subList(trainSize, dataset.size()));

        System.out.println("Test set size: " + testSet.size());
        //test set er data print dibo
        System.out.println("Test set data:");
        for (AttributeLabel al : testSet) {
            System.out.println(al.attributes + " -> " + al.label);
        }
        return new SplitResult(trainSet, testSet);
    }

}
