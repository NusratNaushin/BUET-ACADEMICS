import java.util.HashMap;
import java.util.Map;
public class Node {
    
    int attribute;
    int num_children;
    String label;
    public Map<String, Node> children_map;
    public boolean is_leaf = false;
    int splitting_attribute = -1;

     

    java.util.List<Node> children;
    public Node(int attribute, int num_children, String label) {
        this.attribute = attribute;
        this.label = label;
        children_map = new HashMap<>();
        this.is_leaf = false;
    }

    public Node(boolean is_leaf, String label) {
        this.is_leaf = is_leaf;
        this.label = label;
    }


        public Node() {
        this.attribute = -1;
        this.label = null;
        children_map = new HashMap<>();
        this.is_leaf = false;
    }






}
