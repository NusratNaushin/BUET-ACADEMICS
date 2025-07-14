import java.util.HashMap;
import java.util.Map;


public class AttributeLabel {
        Map<String, String> attributes;
        String label;

        public AttributeLabel(Map<String, String> attributes, String label) {
            this.attributes = new HashMap<>(attributes);
            this.label = label;
        }
    public static String[] headerNames;

    public static void setHeaderNames(String[] headerNames) {
        AttributeLabel.headerNames = headerNames;
    }
}
