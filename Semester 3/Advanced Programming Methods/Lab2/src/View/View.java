package View;
import Controller.Controller;
import Model.*;
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
        while(true){
            String opt;
            System.out.println("Choose your option: ");
            opt = in.next();
            if(opt.equals("0"))
                return;
            switch (opt) {
                case "1":
                    System.out.println("Choose type: ");
                    String type = in.next().toLowerCase();
                    System.out.println("Presented or not (false | true): ");
                    boolean pres = in.nextBoolean();
                    try {
                        switch (type) {
                            case "professor" -> view.add(new Professor(type, pres));
                            case "student" -> view.add(new Student(type, pres));
                            case "specialist" -> view.add(new Specialist(type, pres));
                            default -> System.out.println("Incorrect type");
                        }
                    } catch (Exception e) {
                        System.out.println("ERROR: " + e.getMessage());
                    }
                    break;
                case "2":
                    System.out.println("Choose position to remove: ");
                    int pos = in.nextInt();
                    try {
                        view.remove(pos - 1);
                    } catch (Exception e) {
                        System.out.println("ERROR: " + e.getMessage());
                    }
                    break;
                case "3":
                    for (int i = 0; i < view.getSize(); ++i) {
                        if (view.getPos(i).didPresent())
                            System.out.println(i + 1 + ". " + view.getPos(i).getType() + " - presented work: Yes");
                        else
                            System.out.println(i + 1 + ". " + view.getPos(i).getType() + " - presented work: No");
                    }
                    break;
                default:
                    System.out.println("Wrong option!!!");
                    break;
            }
        }
    }
}
