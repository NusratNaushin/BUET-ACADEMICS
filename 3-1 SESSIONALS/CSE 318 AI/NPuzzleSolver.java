import java.util.*;

public class NPuzzleSolver {

    static class State {
        int[][] board;
        int g; // cost so far
        int h; // heuristic
        int f; // g + h
        State parent;
        int size;

        State(int[][] board, int g, int h, State parent) {
            this.size = board.length;
            this.board = new int[size][size];
            for (int i = 0; i < size; i++)
                this.board[i] = board[i].clone();

            this.g = g;
            this.h = h;
            this.f = g + h;
            this.parent = parent;
        }

        boolean isGoal() {
            int count = 1;
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    if (i == size - 1 && j == size - 1) return board[i][j] == 0;
                    else if (board[i][j] != count++) return false;
            return true;
        }

        List<State> getNeighbors(String heuristicName) {
            List<State> neighbors = new ArrayList<>();
            int[] dx = {-1, 1, 0, 0};
            int[] dy = {0, 0, -1, 1};

            int zx = -1, zy = -1;
            outer:
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    if (board[i][j] == 0) {
                        zx = i; zy = j; break outer;
                    }

            for (int d = 0; d < 4; d++) {
                int nx = zx + dx[d], ny = zy + dy[d];
                if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
                    int[][] newBoard = new int[size][size];
                    for (int i = 0; i < size; i++)
                        newBoard[i] = board[i].clone();
                    newBoard[zx][zy] = newBoard[nx][ny];
                    newBoard[nx][ny] = 0;
                    int newH = Heuristics.calculate(newBoard, heuristicName);
                    neighbors.add(new State(newBoard, g + 1, newH, this));
                }
            }

            return neighbors;
        }

        String boardString() {
            StringBuilder sb = new StringBuilder();
            for (int[] row : board)
                for (int v : row) sb.append(v).append(",");
            return sb.toString();
        }

        void printBoard() {
            for (int[] row : board) {
                for (int v : row) System.out.print(v + " ");
                System.out.println();
            }
            System.out.println();
        }
    }

    static class Heuristics {
        public static int calculate(int[][] board, String name) {
            return switch (name.toLowerCase()) {
                case "manhattan" -> manhattan(board);
                case "hamming" -> hamming(board);
                case "euclidean" -> euclidean(board);
                case "linear" -> linearConflict(board);
                default -> manhattan(board);
            };
        }

        public static int hamming(int[][] board) {
            int count = 0, value = 1, size = board.length;
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++, value++)
                    if (board[i][j] != 0 && board[i][j] != value) count++;
            return count;
        }

        public static int manhattan(int[][] board) {
            int dist = 0, size = board.length;
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++) {
                    int val = board[i][j];
                    if (val != 0) {
                        int targetX = (val - 1) / size;
                        int targetY = (val - 1) % size;
                        dist += Math.abs(i - targetX) + Math.abs(j - targetY);
                    }
                }
            return dist;
        }

        public static int euclidean(int[][] board) {
            int dist = 0, size = board.length;
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++) {
                    int val = board[i][j];
                    if (val != 0) {
                        int targetX = (val - 1) / size;
                        int targetY = (val - 1) % size;
                        dist += Math.sqrt(Math.pow(i - targetX, 2) + Math.pow(j - targetY, 2));
                    }
                }
            return (int) dist;
        }

        public static int linearConflict(int[][] board) {
            int size = board.length;
            int conflicts = 0;

            // row conflict
            for (int i = 0; i < size; i++) {
                int max = -1;
                for (int j = 0; j < size; j++) {
                    int val = board[i][j];
                    if (val != 0 && (val - 1) / size == i) {
                        if (val > max) max = val;
                        else conflicts += 2;
                    }
                }
            }

            // column conflict
            for (int j = 0; j < size; j++) {
                int max = -1;
                for (int i = 0; i < size; i++) {
                    int val = board[i][j];
                    if (val != 0 && (val - 1) % size == j) {
                        if (val > max) max = val;
                        else conflicts += 2;
                    }
                }
            }

            return manhattan(board) + conflicts;
        }
    }

    static boolean isSolvable(int[][] board) {
        int[] flat = Arrays.stream(board).flatMapToInt(Arrays::stream).toArray();
        int size = board.length, inv = 0;
        for (int i = 0; i < flat.length; i++)
            for (int j = i + 1; j < flat.length; j++)
                if (flat[i] != 0 && flat[j] != 0 && flat[i] > flat[j]) inv++;

        System.out.println("size"+size);
        if (size % 2 == 1) return inv % 2 == 0;

        // even grid: blank row from bottom
        int row = 0;
       
        for (int i = size - 1; i >= 0; i--)
            for (int j = 0; j < size; j++)
                if (board[i][j] == 0) {
                    row = size - i;
                    break;
                }

        return (row % 2 == 0) == (inv % 2 == 1);
    }

    public static void solve(int[][] initial, String heuristicName) {
        if (!isSolvable(initial)) {
            System.out.println("Unsolvable puzzle");
            return;
        }

        int h = Heuristics.calculate(initial, heuristicName);
        State start = new State(initial, 0, h, null);
        PriorityQueue<State> pq = new PriorityQueue<>(Comparator.comparingInt(s -> s.f));
        Set<String> visited = new HashSet<>();
        int explored = 0;

        pq.add(start);

        while (!pq.isEmpty()) {
            State current = pq.poll();
            explored++;

            if (current.isGoal()) {
                System.out.println("Minimum number of moves = " + current.g);
                List<State> path = new ArrayList<>();
                while (current != null) {
                    path.add(current);
                    current = current.parent;
                }
                Collections.reverse(path);
                for (State s : path) s.printBoard();
                System.out.println("Total explored nodes = " + explored);
                return;
            }

            visited.add(current.boardString());
            for (State neighbor : current.getNeighbors(heuristicName)) {
                if (!visited.contains(neighbor.boardString()))
                    pq.add(neighbor);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int[][] board = new int[k][k];
        for (int i = 0; i < k; i++)
            for (int j = 0; j < k; j++)
                board[i][j] = sc.nextInt();

        solve(board, "manhattan");  // Change heuristic here
    }
}
