package Controller;
import Repo.Repo;
import Model.Box;

public class Controller {
    Repo ctrl;

    public Controller(Repo repo){
        this.ctrl = repo;
    }

    public void add(Box box) throws IndexOutOfBoundsException{
        this.ctrl.add(box);
    }

    public void delete(int pos) throws IndexOutOfBoundsException{
        this.ctrl.delete(pos);
    }

    public int getSize(){
        return this.ctrl.getSize();
    }

    public Box[] getAll(){
        return this.ctrl.getRepo();
    }
}
