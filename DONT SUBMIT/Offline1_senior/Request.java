import java.util.ArrayList;


public class Request {
    private int request_id;
    private String requester;
    private String description;
    private ArrayList<Pair> uploads;

    public Request(int request_id, String requester, String description){
        this.request_id = request_id;
        this.requester = requester;
        this.description = description;
        uploads = new ArrayList<Pair>();
    }

    public void acceptRequest(String granter, String filepath){
        Pair p = new Pair(granter, filepath);
        uploads.add(p);
    }

    public ArrayList<Pair> getuploads(){
        return uploads;
    }

    public int getRequest_id(){
        return request_id;
    }

    public String getRequester(){
        return requester;
    }

    public String getDescription(){
        return description;
    }

}
