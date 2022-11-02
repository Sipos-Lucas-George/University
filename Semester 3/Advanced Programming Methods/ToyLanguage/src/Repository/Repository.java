package Repository;

import Model.ADT.IList;
import Model.ProgramState;

public class Repository implements IRepository{
    private IList<ProgramState> programStates;

    public Repository(IList<ProgramState> programStates) {
        this.programStates = programStates;
    }

    @Override
    public void addPrg(ProgramState newPrg) {
        programStates.add(newPrg);
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
