package Model.Statements;

import Exceptions.MyException;
import Model.ADT.IStack;
import Model.ADT.MyStack;
import Model.ProgramState;

public class Fork implements IStatement{
    private final IStatement statement;

    public Fork(IStatement statement) {
        this.statement = statement;
    }

    @Override
    public ProgramState execute(ProgramState state) throws MyException {
        IStack<IStatement> newExecStack = new MyStack<>();
        newExecStack.push(statement);
        return new ProgramState(newExecStack, state.getSymTable().cloneDict(), state.getOut(), state.getFileTable(), state.getHeap());
    }

    public String toString(){
        return String.format("Fork{\n%s\n}", this.statement);
    }
}
