package Repo;
import Model.Box;

public class Repo {
    Box[] repo;
    int size = 0;

    public Repo(int cap){
        this.repo = new Box[cap];
    }

    public void add(Box box) throws IndexOutOfBoundsException{
        if(repo.length == size)
            throw new IndexOutOfBoundsException("Index out of bound!");
        this.repo[this.size++] = box;
    }

    public void delete(int pos) throws IndexOutOfBoundsException{
        if(pos < 0 || pos >= size)
            throw new IndexOutOfBoundsException("Position needs to be between 1 and " + size);
        this.repo[pos] = this.repo[--size];
    }

    public int getSize(){
        return this.size;
    }

    public Box[] getRepo(){
        return this.repo;
    }
}
