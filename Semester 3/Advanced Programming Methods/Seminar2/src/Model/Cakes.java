package Model;

public class Cakes implements Box{
    int weight;
    String type = "cake";

    public Cakes(int weight){
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
