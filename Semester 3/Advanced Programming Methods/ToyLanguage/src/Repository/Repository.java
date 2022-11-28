package Repository;

import Exceptions.MyException;
import Model.ADT.IList;
import Model.ADT.MyList;
import Model.ProgramState;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Repository implements IRepository{
    private IList<ProgramState> programStates;
    private final String logFilePath;

    public Repository(String logFilePath) {
        this.programStates = new MyList<>();
        this.logFilePath = logFilePath;
    }

    public Repository(IList<ProgramState> programStates, String logFilePath) throws IOException {
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
    public IList<ProgramState> getProgramStates() {
        return programStates;
    }

    @Override
    public void setProgramStates(IList<ProgramState> programStates) {
        this.programStates = programStates;
    }
}
