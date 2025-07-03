public class DecisionTreeBuild {
    public Node root_attribute;
    public int minimum_split;
    public int max_depth;
    public String attribute_selection_criteria;

   public DecisionTreeBuild(String attribute_selection_criteria , int max_depth) {
       this.root_attribute = null;
       this.minimum_split = 2;
       this.max_depth = max_depth;
       this.attribute_selection_criteria = attribute_selection_criteria;
   } 

   
}
