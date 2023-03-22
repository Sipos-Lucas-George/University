package Model.Statements;

import Exceptions.MyException;
import Model.ADT.IDictionary;
import Model.ADT.IStack;
import Model.ADT.MyStack;
import Model.ProgramState;
import Model.Types.Type;
import Model.Values.Value;

import java.util.Stack;

public class Fork implements IStatement{
    private final IStatement statement;

    public Fork(IStatement statement) {
        this.statement = statement;
    }

    @Override
    public ProgramState execute(ProgramState state) throws MyException {
        IStack<IStatement> newExecStack = new MyStack<>();
        newExecStack.push(statement);
        Stack<IDictionary<String, Value>> newStackReversed = new Stack<>();
        Stack<IDictionary<String, Value>> newStackFinal = new Stack<>();
        while (!state.getSymTable().empty()) {
            newStackReversed.push(state.getSymTable().pop().copy());
        }
        while (!newStackReversed.empty()) {
            newStackFinal.push(newStackReversed.peek().copy());
            state.getSymTable().push(newStackReversed.pop().copy());
        }
        return new ProgramState(newExecStack, newStackFinal, state.getOut(), state.getFileTable(), state.getHeap(), state.getProcedure());
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
