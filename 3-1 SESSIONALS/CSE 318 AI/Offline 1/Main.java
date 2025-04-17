import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int k = sc.nextInt();
            int[][] puzzle = new int[k][k];

            for (int i = 0; i < k; i++) {

                for (int j = 0; j <k; j++) {

                    puzzle[i][j] = sc.nextInt();
                    
                }
                
            }

            sc.nextLine();

            String heuristicName = sc.nextLine().trim().toLowerCase();

            SolvePuzzle.solve(puzzle, heuristicName);
        }
    }
    
}
