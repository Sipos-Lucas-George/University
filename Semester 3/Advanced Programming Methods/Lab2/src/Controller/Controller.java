package Controller;
import Model.Conference;
import Repo.Repo;

public class Controller {
    Repo controller;

    public Controller(Repo controller){
        this.controller = controller;
    }

    public void add(Conference conference) throws Exception{
        if(controller.full())
            throw new Exception("Repo is full!!!");
        this.controller.add(conference);
    }

    public void remove(int pos) throws Exception{
        if(pos < 0 || pos >= controller.getSize())
            throw new Exception("Out of bound!!!");
        this.controller.remove(pos);
    }

    public int getSize(){
        return controller.getSize();
    }

    public Conference getPos(int pos){
        return controller.getPos(pos);
    }

    public Conference[] getAll(){
        return controller.getAll();
    }
}
