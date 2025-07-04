import java.util.List;

public class DecisionTreeBuild {
    public Node root_attribute;
    public int max_depth;
    public String attribute_selection_criteria;

   public DecisionTreeBuild(String attribute_selection_criteria , int max_depth) {
       this.root_attribute = null;
       this.max_depth = max_depth;
       this.attribute_selection_criteria = attribute_selection_criteria;
   } 

   public void train(List<AttributeLabel> dataset){
       this.root_attribute = buildTree(dataset, 0);
   }

   private Node buildTree(List<AttributeLabel> data, int depth){


    
   }

   
}
