package Model.Statements;

import Exceptions.MyException;
import Model.ADT.IDictionary;
import Model.ADT.IStack;
import Model.ADT.MyStack;
import Model.ProgramState;
import Model.Types.Type;

public class Fork implements IStatement{
    private final IStatement statement;

    public Fork(IStatement statement) {
        this.statement = statement;
    }

    @Override
    public ProgramState execute(ProgramState state) throws MyException {
        IStack<IStatement> newExecStack = new MyStack<>();
        newExecStack.push(statement);
        return new ProgramState(newExecStack, state.getSymTable().copy(), state.getOut(), state.getFileTable(), state.getHeap(), state.getSemaphore());
    }

    @Override
    public IDictionary<String, Type> typeCheck(IDictionary<String, Type> typeTable) throws MyException {
        statement.typeCheck(typeTable.copy());
        return typeTable;
    }

    public String toString(){
        return String.format("Fork{\n%s\n}", this.statement);
    }
}
