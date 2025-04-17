
public class Heuristic {
    public static int calculateHeuristic(int[][] puzzle, String hname) {
        String heuristicName = hname.toLowerCase();
        if (heuristicName.equals("hamming")) {
            return hamming(puzzle);
        }

        else if (heuristicName.equals("manhattan")) {
            return manhattan(puzzle);
        }

        else if (heuristicName.equals("euclidian")) {
            return euclidian(puzzle);
        }

        else if (heuristicName.equals("linear")) {
            return linearConflict(puzzle);
        }

        else {
            return -1;
        }

    }

    public static int hamming(int[][] puzzle) {
        int count = 0;
        int value = 1;
        int size = puzzle.length;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++, value++) {
                if (puzzle[i][j] != 0 && puzzle[i][j] != value) {
                    count++;
                }
            }
        }

        return count;
    }

    public static int manhattan(int[][] puzzle) {
        int distance = 0;
        int size = puzzle.length;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int value = puzzle[i][j];

                if (value != 0) {
                    int targetX = (value - 1) / size;
                    int targetY = (value - 1) % size;
                    distance = distance + Math.abs(targetX - i) + Math.abs(targetY - j);
                }
            }
        }

        return distance;
    }

    public static int euclidian(int[][] puzzle) {
        int distance = 0;
        int size = puzzle.length;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int value = puzzle[i][j];

                if (value != 0) {
                    int targetX = (value - 1) / size;
                    int targetY = (value - 1) % size;
                    int squareOfX = (int) Math.pow(i - targetX, 2);
                    int squareOfY = (int) Math.pow(j - targetY, 2);
                    distance = distance + (int) Math.sqrt(squareOfX + squareOfY);

                }
            }
        }

        return (int) distance;
    }

    public static int linearConflict(int[][] puzzle) {

        int conflicts = 0;
        int size = puzzle.length;

        for (int i = 0; i < size; i++) {
            int max = -1;
            for (int j = 0; j < size; j++) {
                int value = puzzle[i][j];
                int isGoalrow = (value - 1) / size;
                if (value != 0 && (isGoalrow == i)) {
                    if (value > max) {
                        max = value;
                    } else {
                        conflicts++;
                    }

                }
            }
        }

        for (int i = 0; i < size; i++) {
            int max = -1;
            for (int j = 0; j < size; j++) {
                int value = puzzle[i][j];
                int isGoalcol = (value - 1) % size;
                if (value != 0 && (isGoalcol == j)) {
                    if (value > max) {
                        max = value;
                    } else {
                        conflicts++;
                    }

                }
            }
        }

        return manhattan(puzzle) + 2 * conflicts;

    }

}
