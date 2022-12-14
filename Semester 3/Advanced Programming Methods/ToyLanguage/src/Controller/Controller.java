package Controller;

import Exceptions.MyException;
import Model.ADT.IList;
import Model.ADT.IStack;
import Model.ADT.Pair;
import Model.ProgramState;
import Model.Statements.CompStatement;
import Model.Statements.IStatement;
import Model.Values.RefValue;
import Model.Values.Value;
import Repository.IRepository;

import java.io.IOException;
import java.util.*;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.stream.Collectors;

public class Controller {
    private final IRepository repository;
    private ExecutorService executor;
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

    public List<ProgramState> getProgramState(){
        return repository.getProgramStates();
    }

    private String displayCurrentProgramState(ProgramState programState){
        if(displayFlag)
            return programState.toString();
        return null;
    }

    List<ProgramState> removeCompletedPrograms(List<ProgramState> programStateList) {
        return programStateList.stream().filter(p -> !p.isCompleted()).collect(Collectors.toList());
    }

    Map<String, Value> safeGarbageCollector(Set<String> symTableAddr, Map<String, Value> heap){
        return heap.entrySet().stream()
                .filter(e -> symTableAddr.contains(e.getKey()))
                .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));
    }

    Set<String> getAddrFromSymTable(List<Collection<Value>> symTableValues, Map<String, Value> heap) {
        Set<String> set = new TreeSet<>();
        symTableValues.forEach(sym -> sym.stream()
                .filter(v -> v instanceof RefValue)
                .forEach(v -> {
                    while (v instanceof RefValue){
                        set.add(((RefValue) v).getAddress());
                        v = heap.get(((RefValue) v).getAddress());
                    }
                })
        );
        return set;
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

    public void oneStepAll(List<ProgramState> programStateList) throws MyException{
        programStateList.forEach(programState -> {
            try{
                repository.logProgramStateExecution(programState);
            } catch (IOException e) {
                System.out.println(e.getMessage());
                System.exit(1);
            }
        });
        List<Callable<ProgramState>> callableList = programStateList.stream()
                .map((ProgramState p) -> (Callable<ProgramState>) (p::oneStep)).collect(Collectors.toList());
        List<Pair<ProgramState, MyException>> newProgramState = null;
        try {
            newProgramState = executor.invokeAll(callableList).stream()
                    .map(programStateFuture -> {
                        try {
                            return new Pair<ProgramState, MyException>(programStateFuture.get(), null);
                        } catch (ExecutionException | InterruptedException e) {
                            if (e.getCause() instanceof MyException) {
                                return new Pair<ProgramState, MyException>(null, (MyException) e.getCause());
                            }
                            System.out.println(e.getMessage());
                            System.exit(1);
                            return null;
                        }
                    }).filter(pair -> pair.first != null || pair.second != null)
                    .collect(Collectors.toList());
        } catch (InterruptedException e) {
            e.printStackTrace();
            System.exit(1);
        }

        for (Pair<ProgramState, MyException> error : newProgramState){
            if(error.second != null)
                throw error.second;
        }

        programStateList.addAll(newProgramState.stream().map(pair -> pair.first).collect(Collectors.toList()));
        repository.setProgramStates(programStateList);
    }

    public IList<String> allSteps() throws MyException{
        this.executor = Executors.newFixedThreadPool(2);
        List<ProgramState> programStateList = removeCompletedPrograms(repository.getProgramStates());
        if(!repository.getCurrentPrg().getOut().isEmpty())
            return repository.getCurrentPrg().getOut();
        IList<String> out = programStateList.get(0).getOut();
        while(!programStateList.isEmpty()){
            ProgramState state = programStateList.get(0);
            state.getHeap().setContent(
                    safeGarbageCollector(
                            getAddrFromSymTable(
                                    programStateList.stream().map(programState -> programState.getSymTable().getContent().values()).collect(Collectors.toList()),
                                    state.getHeap().getContent()
                            ),
                            state.getHeap().getContent()
                    )
            );
            oneStepAll(programStateList);
            programStateList = removeCompletedPrograms(repository.getProgramStates());
        }
        executor.shutdownNow();
        return out;
    }
}
