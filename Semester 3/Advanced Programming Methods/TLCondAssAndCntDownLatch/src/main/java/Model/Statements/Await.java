package Model.Statements;

import Exceptions.MyException;
import Model.ADT.IDictionary;
import Model.ProgramState;
import Model.Types.IntType;
import Model.Types.Type;
import Model.Values.IntValue;
import Model.Values.Value;

import java.util.concurrent.locks.Lock;

public class Await implements IStatement{
    private final String var;

    public Await(String var) {
        this.var = var;
    }

    @Override
    public ProgramState execute(ProgramState state) throws MyException {
        Lock lock = state.getLatch().getLock();
        lock.lock();
        try {
            Value value = state.getSymTable().get(var);
            if(value == null)
                throw new MyException("Value not found in SymTable");
            if(state.getLatch().getLatchTable().get(state.getLatch().getLocation()) != 0)
                state.getExecStack().push(this);
        } catch (MyException e) {
            System.out.println(e.toString());
        } finally {
            lock.unlock();
        }
        return null;
    }

    @Override
    public IDictionary<String, Type> typeCheck(IDictionary<String, Type> typeTable) throws MyException {
        if(!typeTable.get(var).equals(new IntType()))
            throw new MyException("Var is not IntType");
        return typeTable;
    }

    public String toString() {
        return String.format("Await(%s)", var);
    }
}
