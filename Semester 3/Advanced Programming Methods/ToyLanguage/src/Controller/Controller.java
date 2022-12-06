package Controller;

import Exceptions.MyException;
import Model.ADT.IList;
import Model.ADT.IStack;
import Model.ProgramState;
import Model.Statements.IStatement;
import Model.Values.RefValue;
import Model.Values.Value;
import Repository.IRepository;

import java.io.IOException;
import java.util.*;
import java.util.stream.Collectors;

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

    private String displayCurrentProgramState(ProgramState programState){
        if(displayFlag)
            return programState.toString();
        return null;
    }

    Map<String, Value> unsafeGarbageCollector(Set<String> symTableAddr, Map<String, Value> heap){
        return heap.entrySet().stream()
                .filter(e -> symTableAddr.contains(e.getKey()))
                .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));
    }

    Set<String> getAddrFromSymTable(Collection<Value> symTableValues, Map<String, Value> heap) {
        return symTableValues.stream()
                .filter(v -> v instanceof RefValue)
                .map(v -> {
                    RefValue v1= (RefValue) v;
                    return v1.getAddress();
                })
                .collect(Collectors.toSet());
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

    public IList<String> allSteps() throws MyException{
        ProgramState programState = repository.getCurrentPrg();
        try{
            repository.logProgramStateExecution(programState);
            while(!programState.getExecStack().isEmpty()){
                this.oneStep(programState);
                repository.logProgramStateExecution(programState);
                programState.getHeap().setContent(unsafeGarbageCollector(
                        getAddrFromSymTable(programState.getSymTable().values(), programState.getHeap().getContent()),
                        programState.getHeap().getContent()
                ));
            }
        } catch (IOException e){
            System.out.println(e.toString());
        }
        return repository.getCurrentPrg().getOut();
    }
}
