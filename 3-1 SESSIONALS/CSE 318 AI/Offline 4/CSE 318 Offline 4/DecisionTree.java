public class DecisionTree{

public static void main(String[] args) {
    if (args.length != 1) {
        System.out.println("Usage: java DecisionTree <path_to_csv>");
        return;
    }

    DataSetLoad.loadDataSet(args[0]);
}


}