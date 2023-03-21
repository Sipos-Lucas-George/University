package Model.Statements;

import Exceptions.MyException;
import Model.ADT.IDictionary;
import Model.ProgramState;
import Model.Types.IntType;
import Model.Types.Type;

import java.util.concurrent.locks.Lock;

public class Await implements IStatement{
    private final String var;

    public Await(String var) {
        this.var = var;
    }

    @Override
    public ProgramState execute(ProgramState state) throws MyException {
        Lock lock = state.getBarrier().getLock();
        lock.lock();
        try {
            if(!state.getBarrier().getBarrierTable().get(state.getBarrier().getLocation()).second.contains(state.id) && !state.getBarrier().completed()){
                state.getBarrier().getBarrierTable().get(state.getBarrier().getLocation()).second.add(state.id);
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
            throw new MyException("Variable is not IntType");
        return typeTable;
    }

    public String toString() {
        return String.format("Await(%s)", var);
    }
}
