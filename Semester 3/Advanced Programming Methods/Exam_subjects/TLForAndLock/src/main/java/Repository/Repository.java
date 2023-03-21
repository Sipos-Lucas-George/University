package Repository;

import Exceptions.MyException;
import Model.ADT.IList;
import Model.ADT.MyList;
import Model.ProgramState;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class Repository implements IRepository{
    private List<ProgramState> programStates;
    private final String logFilePath;

    public Repository(String logFilePath) {
        this.programStates = new ArrayList<>();
        this.logFilePath = logFilePath;
    }

    public Repository(List<ProgramState> programStates, String logFilePath) throws IOException {
        this.programStates = programStates;
        this.logFilePath = logFilePath;
        new PrintWriter(new BufferedWriter(new FileWriter(this.logFilePath, false)));
    }

    @Override
    public void addPrg(ProgramState newPrg) {
        programStates.add(newPrg);
    }

    @Override
    public void logProgramStateExecution(ProgramState programState) throws IOException {
        PrintWriter file = new PrintWriter(new BufferedWriter(new FileWriter(this.logFilePath, true)));
        file.println(programState);
        file.close();
    }

    @Override
    public ProgramState getCurrentPrg() {
        return programStates.get(0);
    }

    @Override
    public List<ProgramState> getProgramStates() {
        return programStates;
    }

    @Override
    public void setProgramStates(List<ProgramState> programStates) {
        this.programStates = programStates;
    }
}
