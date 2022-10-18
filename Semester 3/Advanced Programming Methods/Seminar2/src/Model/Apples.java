package Model;

public class Apples implements Box{
    int weight;
    String type = "apple";

    public Apples(int weight){
        this.weight = weight;
    }

    @Override
    public boolean ifGreater() {
        return (weight >= min);
    }

    public String getType(){
        return type;
    }

    @Override
    public int getWeight() {
        return this.weight;
    }
}
