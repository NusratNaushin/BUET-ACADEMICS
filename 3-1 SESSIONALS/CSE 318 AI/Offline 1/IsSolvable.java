public class IsSolvable {


    static int getInversionCount(int[] linearPuzzle){
        int inversion_count = 0 ;
        for(int i = 0 ; i < linearPuzzle.length ; i++){
            for(int j = i +1 ; j < linearPuzzle.length ; j++){
                if (linearPuzzle[i] > 0 &&
                linearPuzzle[j] > 0 && linearPuzzle[i] > linearPuzzle[j])
                inversion_count++;
            }
        }


        return inversion_count;
    }

    //0 ta koi ase sheta ber kora lagbe ekhane 
    static int findZeroPosition(int[][] puzzle){

        int N = puzzle.length;
        //nicher theke koto number row te blank space ase sheta finding
        for(int i = N - 1 ; i >= 0 ; i--)
        {
            for (int j = N - 1; j >= 0; j--){
                if(puzzle[i][j] == 0){
                    return (N - i) ; 
                }
            }

        }

        return -1; // bhulbhal input diye blank space na rakhle
    }


    public static boolean isSolvable(int[][] puzzle) { 
        
        int linearPuzzle[];
        linearPuzzle = new int[puzzle.length * puzzle.length];
        int index = 0 ;

        for (int i =0 ; i < puzzle.length ; i ++){
            for (int j = 0 ; j < puzzle.length ; j++){
                linearPuzzle[index] = puzzle[i][j];
                index++;
            }
        }


        // k er value jor hole 
        if (puzzle.length% 2 == 1){
            int inv_count = getInversionCount(linearPuzzle);

            if(inv_count%2 == 0){
                return true;
            }
            else{
                return false;
            }
        }

        else if(puzzle.length% 2 == 0){

            int zeroPos = findZeroPosition(puzzle);
            int inv_count = getInversionCount(linearPuzzle);

            if(zeroPos%2 == 0 && inv_count%2 == 1){
                return true;
            }

            else if(zeroPos%2 == 1 && inv_count%2 == 0){
                return true;
            }

            else{
                return false;
            }

        }



        return true;
    }
}