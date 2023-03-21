package View.CLI;

import Controller.Controller;
import Exceptions.MyException;
import Model.ProgramState;
import Model.Statements.IStatement;
import Repository.IRepository;
import Repository.Repository;
import View.CLI.Commands.ExitCommand;
import View.CLI.Commands.RunExample;
import View.View;

import static View.ExampleView.exampleList;

public class CLIView implements View {
    @Override
    public void execute() {
        TextMenu textMenu = new TextMenu();
        int pos = 1;
        textMenu.addCommand(new ExitCommand("0", "exit"));
        for (IStatement statement : exampleList()) {
            try{
                ProgramState programState = new ProgramState(statement);
                IRepository repository = new Repository("D:\\University\\UNI\\Java\\Final\\src\\main\\java\\Repository\\logFile.txt");
                repository.addPrg(programState);
                Controller controller = new Controller(repository);
                textMenu.addCommand(new RunExample(Integer.toString(pos), statement.toString(), controller));
                ++pos;
            } catch (MyException e) {
                System.out.println(e.toString());
            }
        }
        textMenu.show();
    }
}
