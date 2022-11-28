import View.*;
import View.CLI.CLIView;

public class Main {
    public static void main(String[] args) {
        View view = new CLIView();
        view.execute();
    }
}