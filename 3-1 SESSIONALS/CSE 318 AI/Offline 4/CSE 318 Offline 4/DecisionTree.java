import java.util.List;

public class DecisionTree{

public static void main(String[] args) {
        if (args.length < 3) {
            System.out.println("Usage: java Main <filepath> <criterion: IG|IGR|NWIG> <maxDepth>");
            return;
        }
        String filepath = args[0];
        String criterion = args[1];
        int maxDepth = Integer.parseInt(args[2]);

        double totalAccuracy = 0.0;

        for(int i = 0 ; i < 20 ; i++){

            List<AttributeLabel> dataset = DataSetLoad.loadDataSet(filepath);

            // Split dataset
            Split_Train_and_Test.SplitResult split = Split_Train_and_Test.splitData(dataset, 0.8);

            // Train decision tree
            DecisionTreeBuild tree = new DecisionTreeBuild(split.trainSet, criterion, maxDepth);
            tree.train();

            // Evaluate on test set
            double accuracy = tree.evaluate(split.testSet);
            totalAccuracy += accuracy;
        }
    }

}