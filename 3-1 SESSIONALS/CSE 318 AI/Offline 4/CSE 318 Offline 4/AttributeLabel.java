public class AttributeLabel {
    public String[] attributes;
    public String label;

    public AttributeLabel(String[] attributes, String label) {
        this.attributes = attributes;
        this.label = label;
    }

    public static String[] headerNames;

    public static void setHeaderNames(String[] headerNames) {
        AttributeLabel.headerNames = headerNames;
    }
}
