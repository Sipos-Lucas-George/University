package View;

import Controller.Controller;
import Model.Apples;
import Model.Books;
import Model.Cakes;

import java.util.Scanner;

public class View {
    Controller view;

    public View(Controller view){
        this.view = view;
    }

    public void printMenu(){
        System.out.println("""
                1. Add entity
                2. Remove entity
                3. Print entities
                0. Exit""");
    }

    public void start(){
        printMenu();
        Scanner in = new Scanner(System.in);
        while (true){
            System.out.println("Choose option: ");
            String opt = in.next();
            if(opt.equals("0"))
                return;
            switch (opt) {
                case "1":
                    System.out.println("Choose type: ");
                    String type = in.next().toLowerCase();
                    System.out.println("Give a weight: ");
                    int weight = in.nextInt();
                    try {
                        switch (type) {
                            case "apple" -> view.add(new Apples(weight));
                            case "book" -> view.add(new Books(weight));
                            case "cake" -> view.add(new Cakes(weight));
                            default -> System.out.println("Incorrect type!");
                        }
                    } catch (IndexOutOfBoundsException e) {
                        System.out.println("ERROR: " + e.getMessage());
                    }
                    break;
                case "2":
                    System.out.println("Choose position to remove: ");
                    int pos = in.nextInt();
                    try {
                        view.delete(pos - 1);
                    } catch (IndexOutOfBoundsException e) {
                        System.out.println("ERROR: " + e.getMessage());
                    }
                    break;
                case "3":
                    for (int i = 0; i < view.getSize(); ++i) {
                        if (view.getAll()[i].ifGreater())
                            System.out.println(i + 1 + ". " + view.getAll()[i].getType() + " - weight: " + view.getAll()[i].getWeight());
                    }
                    break;
                default:
                    System.out.println("Wrong option!!!");
                    break;
            }
        }
    }
}
