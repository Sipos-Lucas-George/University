package Repo;
import Model.Conference;

public class Repo {
    Conference[] repo;
    int size;

    public Repo(int capacity){
        this.repo = new Conference[capacity];
        this.size = 0;
    }

    public void add(Conference entity){
        this.repo[size++] = entity;
    }

    public void remove(int pos){
        for (int i = pos; i < this.size - 1; ++i)
            this.repo[i] = this.repo[i + 1];
        --this.size;
    }

    public boolean full(){
        return repo.length == size;
    }

    public int getSize(){
        return this.size;
    }

    public Conference getPos(int pos){
        return repo[pos];
    }

    public Conference[] getAll(){
        return this.repo;
    }
}
