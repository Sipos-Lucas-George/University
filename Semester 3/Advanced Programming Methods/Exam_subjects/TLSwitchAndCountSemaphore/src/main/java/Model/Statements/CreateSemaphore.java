package Model.Statements;

import Exceptions.MyException;
import Model.ADT.IDictionary;
import Model.ADT.Pair;
import Model.Expressions.Expression;
import Model.ProgramState;
import Model.Types.IntType;
import Model.Types.Type;
import Model.Values.IntValue;

import java.util.ArrayList;

public class CreateSemaphore implements IStatement{
    private final String var;
    private final Expression expression;
    public CreateSemaphore(String var, Expression expression) {
        this.var = var;
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState state) throws MyException {
        IntValue value = (IntValue) expression.eval(state.getSymTable(), state.getHeap());
        Integer location = state.getSemaphore().getSemaphoreLocation();
        state.getSymTable().put(var, new IntValue(location));
        state.getSemaphore().getSemaphoreTable().put(location, new Pair<>(value.getValue(), new ArrayList<>()));
        return null;
    }

    @Override
    public IDictionary<String, Type> typeCheck(IDictionary<String, Type> typeTable) throws MyException {
        if(!typeTable.containsKey(var))
            throw new MyException("Variable not in TypeTable");
        if(!expression.typeCheck(typeTable).equals(new IntType()))
            throw new MyException("Expression not an IntType");
        return typeTable;
    }

    public String toString() {
        return String.format("Create Semaphore(%s: %s)", var, expression.toString());
    }
}
