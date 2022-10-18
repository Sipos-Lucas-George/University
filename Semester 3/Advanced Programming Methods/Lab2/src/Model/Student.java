package Model;

public class Student implements Conference{
    boolean presented;
    String type;

    public Student(String type, boolean presented){
        this.presented = presented;
        this.type = type;
    }

    @Override
    public boolean didPresent() {
        return presented;
    }

    @Override
    public String getType() {
        return this.type;
    }
}
