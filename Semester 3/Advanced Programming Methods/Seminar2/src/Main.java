import Controller.Controller;
import Repo.Repo;
import View.View;

public class Main {
    public static void main(String[] args) {
        Repo repo = new Repo(100);
        Controller ctrl = new Controller(repo);
        View view = new View(ctrl);
        view.start();
    }
}