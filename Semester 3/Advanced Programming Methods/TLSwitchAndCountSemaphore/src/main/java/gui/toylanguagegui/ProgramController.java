package gui.toylanguagegui;

import Controller.Controller;
import Exceptions.MyException;
import Model.ADT.*;
import Model.ProgramState;
import Model.Statements.IStatement;
import Model.Values.Value;
import javafx.beans.property.SimpleStringProperty;
import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.scene.control.*;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Objects;

public class ProgramController {
    private Controller controller;

    @FXML
    private TableColumn<Pair<Integer, Pair<Integer, List<Integer>>>, String> SemCol1;

    @FXML
    private TableColumn<Pair<Integer, Pair<Integer, List<Integer>>>, String> SemCol2;

    @FXML
    private TableView<Pair<Integer, Pair<Integer, List<Integer>>>> SemTable;

    @FXML
    private TableView<Pair<String, Value>> heapTableView;

    @FXML
    private TableColumn<Pair<String, Value>, String> addressCol;

    @FXML
    private TableColumn<Pair<String, Value>, String> addressValCol;

    @FXML
    private ListView<String> execListView;

    @FXML
    private ListView<String> fileListView;

    @FXML
    private ListView<String> outListView;

    @FXML
    private ListView<Integer> programListView;

    @FXML
    private TextField programStateField;

    @FXML
    private Button oneStepButton;

    @FXML
    private TableView<Pair<String, Value>> symTableView;

    @FXML
    private TableColumn<Pair<String, Value>, String> nameCol;

    @FXML
    private TableColumn<Pair<String, Value>, String> valueCol;

    public void setController(Controller controller) {
        this.controller = controller;
        this.populate();
    }

    private ProgramState getProgramState(){
        if(controller.getProgramState().isEmpty())
            return null;
        int currentID = this.programListView.getSelectionModel().getSelectedIndex();
        if (currentID < 0)
            return controller.getProgramState().get(0);
        return controller.getProgramState().get(currentID);
    }

    public void initialize() {
        addressCol.setCellValueFactory(p -> new SimpleStringProperty(p.getValue().first));
        addressValCol.setCellValueFactory(p -> new SimpleStringProperty(p.getValue().second.toString()));
        nameCol.setCellValueFactory(p -> new SimpleStringProperty(p.getValue().first));
        valueCol.setCellValueFactory(p -> new SimpleStringProperty(p.getValue().second.toString()));
        SemCol1.setCellValueFactory(p -> new SimpleStringProperty(p.getValue().first.toString()));
        SemCol2.setCellValueFactory(p -> new SimpleStringProperty(p.getValue().second.first.toString() + ": " + p.getValue().second.second.toString()));

        this.oneStepButton.setOnAction(actionEvent -> {
            this.populate();
            if(controller == null){
                Alert alert = new Alert(Alert.AlertType.ERROR, "The program was not selected", ButtonType.OK);
                alert.showAndWait();
                return;
            }
            boolean programStateLeft = Objects.requireNonNull(getProgramState()).getExecStack().isEmpty();
            if(programStateLeft) {
                Alert alert = new Alert(Alert.AlertType.ERROR, "Nothing left to execute", ButtonType.OK);
                alert.showAndWait();
                return;
            }
            try {
                this.controller.oneStepAllGui();
                this.populate();
            } catch (MyException myException) {
                Alert alert = new Alert(Alert.AlertType.ERROR, myException.getMessage(), ButtonType.OK);
                alert.showAndWait();
            }
        });
        programListView.setOnMouseClicked(mouseEvent -> this.populate());
    }

    private void populate() {
        this.populateExec();
        this.populateFile();
        this.populateHeap();
        this.populateSem();
        this.populateOut();
        this.populateSym();
        this.populatePrgState();
    }

    private void populatePrgState() {
        List<ProgramState> programStateList = controller.getProgramState();
        var idList = programStateList.stream().map(p -> p.id).toList();
        this.programListView.setItems(FXCollections.observableList(idList));
        this.programListView.refresh();
        this.programStateField.setText("" + programStateList.size());
    }

    private void populateSym() {
        ProgramState programState = getProgramState();
        List<Pair<String, Value>> symTableList = new ArrayList<>();
        if(programState != null)
            for(Map.Entry<String, Value> entry : programState.getSymTable().getContent().entrySet())
                symTableList.add(new Pair<>(entry.getKey(), entry.getValue()));
        this.symTableView.setItems(FXCollections.observableList(symTableList));
        this.symTableView.refresh();
    }

    private void populateOut() {
        IList<String> output;
        if(!controller.getProgramState().isEmpty())
            output = controller.getProgramState().get(0).getOut();
        else
            output = new MyList<>();
        this.outListView.setItems(FXCollections.observableList(output.getList()));
        this.outListView.refresh();
    }

    private void populateHeap() {
        IHeap heap;
        if (!controller.getProgramState().isEmpty())
            heap = controller.getProgramState().get(0).getHeap();
        else
            heap = new MyHeap();

        List<Pair<String, Value>> heapTableList = new ArrayList<>();
        for (Map.Entry<String, Value> entry : heap.getContent().entrySet())
            heapTableList.add(new Pair<>(entry.getKey(), entry.getValue()));
        this.heapTableView.setItems(FXCollections.observableList(heapTableList));
        this.heapTableView.refresh();
    }

    private void populateSem() {
        ISemaphore semaphore;
        if(!controller.getProgramState().isEmpty())
            semaphore = controller.getProgramState().get(0).getSemaphore();
        else
            semaphore = new MySemaphore();

        List<Pair<Integer, Pair<Integer, List<Integer>>>> semaphoreTableList = new ArrayList<>();
        for(Map.Entry<Integer, Pair<Integer, List<Integer>>> entry : semaphore.getSemaphoreTable().entrySet())
            semaphoreTableList.add(new Pair<>(entry.getKey(), new Pair<>(entry.getValue().first, entry.getValue().second)));
        this.SemTable.setItems(FXCollections.observableList(semaphoreTableList));
        this.SemTable.refresh();
    }

    private void populateFile() {
        ArrayList<String> file;
        if(!controller.getProgramState().isEmpty())
            file = new ArrayList<>(controller.getProgramState().get(0).getFileTable().keys());
        else
            file = new ArrayList<>();
        this.fileListView.setItems(FXCollections.observableArrayList(file));
        this.fileListView.refresh();
    }

    private void populateExec() {
        ProgramState state = getProgramState();
        List<String> execList = new ArrayList<>();
        if(state != null)
            for (IStatement statement : state.getExecStack().getStack())
                execList.add(statement.toString());
        this.execListView.setItems(FXCollections.observableList(execList));
        this.execListView.refresh();
    }
}
