package Model.Statements;

import Exceptions.MyException;
import Model.ADT.IDictionary;
import Model.ADT.Pair;
import Model.Expressions.Expression;
import Model.ProgramState;
import Model.Types.IntType;
import Model.Types.Type;
import Model.Values.IntValue;

public class NewLatch implements IStatement{
    private final String var;
    private final Expression expression;

    public NewLatch(String var, Expression expression) {
        this.var = var;
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState state) throws MyException {
        IntValue value = (IntValue) expression.eval(state.getSymTable(), state.getHeap());
        if(!(value.getType() instanceof IntType))
            throw new MyException("Expression is not IntType");
        Integer location = state.getLatch().getLocation();
        state.getSymTable().put(var, new IntValue(location));
        state.getLatch().getLatchTable().put(location, value.getValue());
        return null;
    }

    @Override
    public IDictionary<String, Type> typeCheck(IDictionary<String, Type> typeTable) throws MyException {
        if(!typeTable.get(var).equals(new IntType()) || !expression.typeCheck(typeTable).equals(new IntType()))
            throw new MyException("The Latch arguments are not of IntType");
        return typeTable;
    }

    public String toString() {
        return String.format("NewLatch(%s, %s)",var,expression.toString());
    }
}
