package Model;

public class Professor implements Conference {
    boolean presented;
    String type;

    public Professor(String type, boolean presented){
        this.presented = presented;
        this.type = type;
    }

    @Override
    public boolean didPresent() {
        return presented;
    }

    @Override
    public String getType() {
        return type;
    }
}
