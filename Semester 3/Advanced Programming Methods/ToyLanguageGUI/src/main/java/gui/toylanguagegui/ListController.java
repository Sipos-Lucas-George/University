package gui.toylanguagegui;

import Controller.Controller;
import Exceptions.MyException;
import Model.ProgramState;
import Model.Statements.IStatement;
import Repository.IRepository;
import Repository.Repository;
import View.ExampleView;
import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.ButtonType;
import javafx.scene.control.ListView;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Region;

public class ListController {

    private ProgramController programController;

    public void setProgramController(ProgramController programController) {
        this.programController = programController;
    }

    @FXML
    private ListView<IStatement> stateList;

    @FXML
    public void initialize() {
        stateList.setItems(FXCollections.observableArrayList(ExampleView.exampleList()));
    }

    @FXML
    public void startProgram(MouseEvent mouseEvent) {
        int index = this.stateList.getSelectionModel().getSelectedIndex();
        if(index < 0)
            return;
        ProgramState programState = new ProgramState(ExampleView.exampleList()[index]);
        IRepository repository = new Repository("D:\\University\\UNI\\Java\\ToyLanguageGUI\\src\\main\\java\\Repository\\logFile.txt");
        Controller controller = new Controller(repository);
        controller.addPrg(programState);
        try {
            controller.typeChecker();
            this.programController.setController(controller);
        } catch (MyException myException) {
            Alert alert = new Alert(Alert.AlertType.ERROR, myException.getMessage(), ButtonType.OK);
            alert.getDialogPane().setMinHeight(Region.USE_COMPUTED_SIZE);
            alert.showAndWait();
        }
    }
}
