import java.util.*;

public class searchNode {
    int[][] puzzle;
    int g;
    int h;
    int f;
    searchNode parent;
    int size;

    searchNode(int[][] puzzle, int g, int h, searchNode parent) {
        this.size = puzzle.length;
        this.puzzle = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                this.puzzle[i][j] = puzzle[i][j];

            }
        }

        this.g = g;
        this.h = h;
        this.f = g + h;
        this.parent = parent;

    }

    boolean isTargetPuzzleState() {

        int value = 1;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i == size - 1 && j == size - 1) {
                    if (puzzle[i][j] != 0) {
                        return false;
                    } else {
                        return true;
                    }
                } else if (puzzle[i][j] != value) {
                    return false;
                }

                value++;
            }

        }

        return true;
    }

    List<searchNode> getChildren(String heuristicName) {

        List<searchNode> children = new ArrayList<>();

        int blankSpaceRow = -1;
        int blankSpaceCol = -1;

        int[] x_moves = { -1, 1, 0, 0 };
        int[] y_moves = { 0, 0, -1, 1 };

        boolean foundBlankTile = false;

        for (int i = 0; i < size && !foundBlankTile; i++) {

            for (int j = 0; j < size; j++) {

                if (puzzle[i][j] == 0) {
                    blankSpaceRow = i;
                    blankSpaceCol = j;
                    foundBlankTile = true;
                    break;
                }

            }

        }

        for (int d = 0; d < 4; d++) {

            int new_x = blankSpaceRow + x_moves[d];
            int new_y = blankSpaceCol + y_moves[d];

            if (new_x >= 0 && new_x < size && new_y >= 0 && new_y < size) {

                int[][] newPuzzle = new int[size][size];
                for (int i = 0; i < size; i++) {
                    for (int j = 0; j < size; j++) {

                        newPuzzle[i][j] = puzzle[i][j];

                    }
                }

                newPuzzle[blankSpaceRow][blankSpaceCol] = newPuzzle[new_x][new_y];
                newPuzzle[new_x][new_y] = 0;

                int newG = g + 1;

                int newH = Heuristic.calculateHeuristic(newPuzzle, heuristicName);
                children.add(new searchNode(newPuzzle, newG, newH,this));
            }

        }

        return children;

    }

    String getPuzzleString() {
        String result = "";
        for (int i = 0; i < puzzle.length; i++) {
            for (int j = 0; j < puzzle.length; j++) {
                result += puzzle[i][j];
                if (!(i == puzzle.length - 1 && j == puzzle.length - 1)) {
                    result += ",";
                }
            }

        }

        return result;
    }

    void printPuzzle() {
        for (int[] row : puzzle) {

            for (int value : row) {

                System.out.print(value + " ");

            }
            System.out.println();

        }
        System.out.println();
    }

}
