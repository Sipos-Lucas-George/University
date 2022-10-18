package Model;

public class Specialist implements Conference{
    boolean presented;
    String type;

    public Specialist(String type, boolean presented){
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
