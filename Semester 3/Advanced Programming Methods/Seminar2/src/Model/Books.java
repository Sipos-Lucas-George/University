package Model;

public class Books implements Box{
    int weight;
    String type = "book";

    public Books(int weight){
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
