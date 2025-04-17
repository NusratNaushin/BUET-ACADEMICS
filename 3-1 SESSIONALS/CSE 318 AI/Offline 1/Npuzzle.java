import java.util.*;

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


        boolean isTargetPuzzleState(){

        
            int value = 1;
            for(int i = 0 ; i < size ; i++){
                for(int j = 0 ; j < size ; j ++){
                    if(i == size - 1 && j == size - 1){
                        if(puzzle[i][j] != 0){
                            return false;
                        }
                        else{
                            return true;
                        }
                    }
                    else if(puzzle[i][j] != value){
                        return false ;
                    }

                    value++;
                }
                
            }
    
    
    
            return true;
        }


        List<searchNode> getChildren(String heuristicName){

            List<searchNode> children = new ArrayList<>();

            int blankSpaceRow = -1;
            int blankSpaceCol = -1;

            int[] x_moves = {-1,1,0,0};
            int[] y_moves = { 0,0,-1,1};






            return children;
        
    }

}

}
