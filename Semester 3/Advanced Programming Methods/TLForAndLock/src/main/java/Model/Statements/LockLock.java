package Model.Statements;

import Exceptions.MyException;
import Model.ADT.IDictionary;
import Model.ADT.Pair;
import Model.ProgramState;
import Model.Types.IntType;
import Model.Types.Type;
import Model.Values.IntValue;

import java.util.concurrent.locks.Lock;

public class LockLock implements IStatement{
    private final String var;

    public LockLock(String var) {
        this.var = var;
    }

    @Override
    public ProgramState execute(ProgramState state) throws MyException {
        IntValue value = (IntValue) state.getSymTable().get(var);
        if(value == null)
            throw new MyException("Value not found in SymTable");
        Lock lock = state.getLockTable().getLock(value.getValue());
        lock.lock();
        try {
            if(state.getLockTable().getLockTable().get(value.getValue()).second == null) {
                state.getLockTable().getLockTable().put(value.getValue(), new Pair<>(lock, state.id));
            }
            else {
                state.getExecStack().push(this);
            }
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
            throw new MyException("Var is not an IntType");
        return typeTable;
    }

    public String toString() {
        return String.format("Lock(%s)",var);
    }
}
