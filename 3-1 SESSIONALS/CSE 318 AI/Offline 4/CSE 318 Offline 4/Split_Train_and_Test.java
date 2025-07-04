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
        Collections.shuffle(dataset, new Random());
        int trainSize = (int) (dataset.size() * trainRatio);
        List<AttributeLabel> trainSet = new ArrayList<>(dataset.subList(0, trainSize));
        List<AttributeLabel> testSet = new ArrayList<>(dataset.subList(trainSize, dataset.size()));
        return new SplitResult(trainSet, testSet);
    }

}
