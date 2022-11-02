package Controller;

import Exceptions.MyException;
import Model.ADT.IList;
import Model.ADT.IStack;
import Model.ProgramState;
import Model.Statements.IStatement;
import Repository.IRepository;

public class Controller {
    private final IRepository repository;
    private boolean displayFlag;

    public Controller(IRepository repository) {
        this.repository = repository;
        this.displayFlag = false;
    }

    public void setDisplayFlagOn() { this.displayFlag = true; }
    public void setDisplayFlagOff() { this.displayFlag = false; }

    public void addPrg(ProgramState newPrg){
        repository.addPrg(newPrg);
    }

    public IList<ProgramState> getProgramState(){
        return repository.getProgramStates();
    }

    private void displayCurrentProgramState(ProgramState programState){
        if(displayFlag)
            System.out.println(programState.toString());
    }

    public ProgramState oneStep(ProgramState programState) throws MyException{
        IStack<IStatement> stack = programState.getExecStack();
        if(stack.isEmpty()){
            throw new MyException("Program state is empty!");
        }
        IStatement currentStatement = stack.pop();
        this.displayCurrentProgramState(programState);
        return currentStatement.execute(programState);
    }

    public void allSteps() throws MyException{
        ProgramState programState = repository.getCurrentPrg();
        while(!programState.getExecStack().isEmpty()){
            this.oneStep(programState);
        }
    }
}
