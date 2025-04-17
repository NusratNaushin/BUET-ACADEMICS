import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class SolvePuzzle {

    public static void solve(int[][] initialPuzzle, String heuristicName) {
        if (!IsSolvable.isSolvable(initialPuzzle)) {
            System.out.println("Unsolvable");
            return;
        }

        int h = Heuristic.calculateHeuristic(initialPuzzle, heuristicName);

        searchNode root = new searchNode(initialPuzzle, 0, h, null);
        PriorityQueue<searchNode> pq = new PriorityQueue<>(Comparator.comparingInt(s -> s.f));
        Set<String> visited = new HashSet<>();

        int explored = 0;

        pq.add(root);

        while (!pq.isEmpty()) {

            searchNode currentNode = pq.poll();
            explored++;

            currentNode.printPuzzle();

            if (currentNode.isTargetPuzzleState()) {
                System.out.println("Minimum number of moves = " + currentNode.g);
                List<searchNode> path = new ArrayList<>();

                while (currentNode != null) {

                    path.add(currentNode);
                    currentNode = currentNode.parent;

                }
                Collections.reverse(path);
                for (searchNode s : path) {

                    s.printPuzzle();

                }

                System.out.println("Total explored nodes = " + explored);
                return;

            }

            visited.add(currentNode.getPuzzleString());

            for (searchNode children : currentNode.getChildren(heuristicName)) {
                if (!visited.contains(children.getPuzzleString())) {
                    pq.add(children);
                }
            }

        }
    }

}
