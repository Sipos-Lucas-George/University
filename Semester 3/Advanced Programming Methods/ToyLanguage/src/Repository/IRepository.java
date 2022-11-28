package Repository;

import Model.ADT.IList;
import Model.ProgramState;

import java.io.IOException;

public interface IRepository {
    void addPrg(ProgramState newPrg);
    void logProgramStateExecution(ProgramState programState) throws IOException;
    ProgramState getCurrentPrg();
    IList<ProgramState> getProgramStates();
    void setProgramStates(IList<ProgramState> programStates);
}
