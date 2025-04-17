public class Npuzzle {

    static class searchNode {
        int[][] puzzle;
        int g;
        int h;
        int f;
        searchNode parent;
        int size;

        searchNode(int[][] puzzle, int g, int h,searchNode parent) {
            this.size = puzzle.length;
            this.puzzle = new int[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    this.puzzle[i][j] = puzzle[i][j];

                }
            }

            this.g = g ;
            this.h = h;
            this.f = g + h;

        }

        
    }

}
