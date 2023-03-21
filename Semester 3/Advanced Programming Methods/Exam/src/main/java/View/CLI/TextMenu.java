package View.CLI;

import Model.ADT.IDictionary;
import Model.ADT.MyDictionary;
import View.CLI.Commands.Command;

import java.util.Scanner;

public class TextMenu {
    private final IDictionary<String, Command> commands;

    public TextMenu() {
        this.commands = new MyDictionary<>();
    }

    public void addCommand(Command command) {
        commands.put(command.getKey(), command);
    }

    private void printMenu() {
        for (String command : commands.keys().stream().sorted((o1, o2) -> {
            int int1 = Integer.parseInt(o1);
            int int2 = Integer.parseInt(o2);
            return Integer.compare(int1, int2);
        }).toList()) {
            System.out.printf("%s: \n%s\n%n\n", commands.get(command).getKey(), commands.get(command).getDescription());
        }
    }

    public void show() {
        Scanner scanner = new Scanner(System.in);
        printMenu();
        while (true) {
            System.out.print(">> ");
            String key = scanner.nextLine();
            if (key.equals("exit"))
                break;
            Command command = commands.get(key);
            if (command == null) {
                System.out.println("Invalid input!");
                continue;
            }
            command.execute();
        }
    }
}
