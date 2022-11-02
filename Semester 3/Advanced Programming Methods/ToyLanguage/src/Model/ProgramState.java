package Model;

import Exceptions.MyException;
import Model.ADT.*;
import Model.Statements.IStatement;
import Model.Values.Value;

public class ProgramState {
    private final IStack<IStatement> execStack;
    private final IDictionary<String, Value> symTable;
    private final IList<String> out;

    public ProgramState(){
        execStack = new MyStack<>();
        symTable = new MyDictionary<>();
        out = new MyList<>();
    }

    public ProgramState(IStack<IStatement> execStack, IDictionary<String, Value> symTable, IList<String> out) {
        this.execStack = execStack;
        this.symTable = symTable;
        this.out = out;
    }

    public IStack<IStatement> getExecStack(){
        return this.execStack;
    }

    public IDictionary<String, Value> getSymTable() {
        return symTable;
    }

    public IList<String> getOut() {
        return out;
    }

    public boolean isCompleted(){
        return execStack.isEmpty();
    }

    public ProgramState thisStep() throws MyException {
        if(execStack.isEmpty())
            throw new MyException("ERROR: Execution stack is empty!");
        IStatement statement = execStack.pop();
        return statement.execute(this);
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
        for(String key : symTable.keys()){
            builder.append(String.format("%s : %s\n", key, symTable.get(key)));
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

    @Override
    public String toString(){
        return String.format("Execution Stack:\n%s\nSymbol Table:\n%s\nOut:\n%s",
                execToString(),
                symToString(),
                outToString());
    }
}
