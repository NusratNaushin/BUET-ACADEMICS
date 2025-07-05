import java.util.List;

public class DecisionTree {

    public static void main(String[] args) {
        if (args.length < 3) {
            System.out.println("Usage: java Main <filepath> <criterion: IG|IGR|NWIG> <maxDepth>");
            return;
        }
        String filepath = args[0];
        String criterion = args[1];
        int maxDepth = Integer.parseInt(args[2]);

        double totalAccuracy = 0.0;
        double nodeCount = 0.0;

        double unpruned_depth_count_in_main = 0.0;

        for (int i = 0; i < 20; i++) {

            List<AttributeLabel> dataset = DataSetLoad.loadDataSet(filepath);

            Split_Train_and_Test.SplitResult split = Split_Train_and_Test.splitData(dataset, 0.8);

            DecisionTreeBuild tree = new DecisionTreeBuild(criterion, maxDepth);
            tree.train(split.trainSet);

            // Evaluate on test set
            double accuracy = tree.calculateAccuracy(split.testSet);
            // tree te koita node ase count korbo
            nodeCount += tree.countNodes(tree.root_attribute);
            totalAccuracy += accuracy;
            unpruned_depth_count_in_main += tree.unpruned_depth_count;
            // System.out.printf("Run %d accuracy: %.2f%%\n", i + 1, accuracy * 100);
        }

        // avg node count korbo
        double avgNodeCount = nodeCount / 20.0;
        System.out.printf("Node Count: %.2f max depth %d and chosen Criteria %s  \n", avgNodeCount, maxDepth,
                criterion);
        if (maxDepth == 0) {
            System.out.printf("Unpruned depth count : %.2f\n", unpruned_depth_count_in_main / 20.0);
        }
        System.out.printf("Average Accuracy over 20 runs for max depth %d: and chosen Criteria %s :%.2f%%\n", maxDepth,
                criterion, (totalAccuracy / 20.0) * 100);
    }

}