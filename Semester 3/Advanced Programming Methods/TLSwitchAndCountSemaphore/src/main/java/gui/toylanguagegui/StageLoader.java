package gui.toylanguagegui;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class StageLoader extends Application {
    @Override
    public void start(Stage stage1) throws IOException {
        FXMLLoader listLoader = new FXMLLoader(StageLoader.class.getResource("firstWindow.fxml"));
        stage1.setScene(new Scene(listLoader.load(), 1500, 800));
        ListController listController = listLoader.getController();
        stage1.setTitle("Select Program");

        FXMLLoader programLoader = new FXMLLoader(StageLoader.class.getResource("secondWindow.fxml"));
        Stage stage2 = new Stage();
        stage2.setScene(new Scene(programLoader.load(), 1500, 800));
        ProgramController programController = programLoader.getController();
        listController.setProgramController(programController);
        stage2.setTitle("Program state");

        stage2.show();
        stage1.show();
    }

    public static void main(String[] args) {
        launch();
    }
}