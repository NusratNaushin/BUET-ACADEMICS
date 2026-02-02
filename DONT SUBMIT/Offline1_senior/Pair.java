public class Pair {
    private String uploader_id ;
    private String filepath;

    public Pair(String uploader_id, String filepath)
    {
        this.uploader_id = uploader_id;
        this.filepath = filepath;
    }

    public String getUploader_id() {
        return uploader_id;
    }

    public void setUploader_id(String uploader_id) {
        this.uploader_id = uploader_id;
    }

    public String getFilepath() {
        return filepath;
    }

    public void setFilepath(String filepath) {
        this.filepath = filepath;
    }
}
