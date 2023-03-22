package Model;

import Exceptions.MyException;
import Model.ADT.*;
import Model.Statements.CompStatement;
import Model.Statements.IStatement;
import Model.Values.Value;

import java.io.BufferedReader;
import java.util.Map;
import java.util.Random;
import java.util.Stack;
import java.util.TreeSet;

import static java.lang.Math.abs;

public class ProgramState {
    private final IStack<IStatement> execStack;
    private final Stack<IDictionary<String, Value>> symTable;
    private final IList<String> out;
    private final IDictionary<String, BufferedReader> fileTable;
    private final IHeap heap;
    private static final TreeSet<Integer> ids = new TreeSet<>();
    public final Integer id;
    private final IProcedure procedure;

    public ProgramState(IStatement originalProgram) {
        execStack = new MyStack<>();
        symTable = new Stack<>();
        symTable.push(new MyDictionary<>());
        out = new MyList<>();
        fileTable = new MyDictionary<>();
        execStack.push(originalProgram);
        heap = new MyHeap();
        id = newID();
        procedure = new MyProcedure();
    }

    public ProgramState(){
        execStack = new MyStack<>();
        symTable = new Stack<>();
        symTable.push(new MyDictionary<>());
        out = new MyList<>();
        fileTable = new MyDictionary<>();
        heap = new MyHeap();
        id = newID();
        procedure = new MyProcedure();
    }

    public ProgramState(IStack<IStatement> execStack, Stack<IDictionary<String, Value>> symTable, IList<String> out, IDictionary<String, BufferedReader> fileTable, IHeap heap, IProcedure procedure) {
        this.execStack = execStack;
        this.symTable = symTable;
        this.out = out;
        this.fileTable = fileTable;
        this.heap = heap;
        this.procedure = procedure;
        id = newID();
    }

    public IStack<IStatement> getExecStack(){
        return this.execStack;
    }

    public Stack<IDictionary<String, Value>> getSymTable() {
        return symTable;
    }

    public IList<String> getOut() {
        return out;
    }

    public IDictionary<String, BufferedReader> getFileTable() {
        return fileTable;
    }

    public IHeap getHeap() {
        return heap;
    }
    public IProcedure getProcedure() {
        return procedure;
    }

    public boolean isCompleted(){
        return execStack.isEmpty();
    }

    protected IStatement loadFork(IStatement statement){
        while (statement instanceof CompStatement){
            statement.execute(this);
            statement = this.execStack.pop();
        }
        return statement;
    }

    public ProgramState oneStep() throws MyException {
        if(execStack.isEmpty())
            throw new MyException("ERROR: Execution stack is empty!");
        IStatement statement = execStack.pop();
        if(statement instanceof CompStatement){
            statement = loadFork(statement);
        }
        return statement.execute(this);
    }

    private static int newID() {
        Random random = new Random();
        int _id;
        synchronized (ids){
            do {
                _id = 1000 + abs((random.nextInt() % 9000));
            } while (ids.contains(_id));
            ids.add(_id);
        }
        return _id;
    }

    public String execToString(){
        StringBuilder builder = new StringBuilder();
        for(IStatement statement : execStack){
            builder.append(statement.toString()).append("\n");
        }
        return builder.toString();
    }

    public String symToString(){
        StringBuilder builder = new StringBuilder();
        for(String key : symTable.peek().keys()){
            builder.append(String.format("%s : %s\n", key, symTable.peek().get(key)));
        }
        return builder.toString();

    }

    public String outToString(){
        StringBuilder builder = new StringBuilder();
        for(String o : out){
            builder.append(o).append("\n");
        }
        return builder.toString();
    }
    public String fileToString(){
        StringBuilder builder = new StringBuilder();
        for(String o : fileTable.keys()){
            builder.append(o).append("\n");
        }
        return builder.toString();
    }

    public String heapToString(){
        StringBuilder builder = new StringBuilder();
        Map<String, Value> map = heap.getContent();
        for (String key : map.keySet()){
            builder.append(key).append(" in ").append(map.get(key)).append("\n");
        }
        return builder.toString();
    }

    @Override
    public String toString(){
        return String.format("ID: %d\nExecution Stack:\n%s\nSymbol Table:\n%s\nOut:\n%s\nFile Table:\n%s\nHeap:\n%s",
                id,
                execToString(),
                symToString(),
                outToString(),
                fileToString(),
                heapToString()
        );
    }
}
