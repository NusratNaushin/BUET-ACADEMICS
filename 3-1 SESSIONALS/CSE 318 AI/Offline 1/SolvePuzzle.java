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
        PriorityQueue<searchNode> openList = new PriorityQueue<>(Comparator.comparingInt(s -> s.f));
        Set<String> closedList = new HashSet<>();

        int explored = 0;

        openList.add(root);

        while (!openList.isEmpty()) {

            searchNode currentNode = openList.poll();
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

            closedList.add(currentNode.getPuzzleString());

            for (searchNode children : currentNode.getChildren(heuristicName)) {
                if (!closedList.contains(children.getPuzzleString())) {
                    openList.add(children);
                }
            }

        }
    }

}
