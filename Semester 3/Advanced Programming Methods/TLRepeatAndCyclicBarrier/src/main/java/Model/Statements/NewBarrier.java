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

public class NewBarrier implements IStatement{
    private final String var;
    private final Expression expression;

    public NewBarrier(String var, Expression expression) {
        this.var = var;
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState state) throws MyException {
        IntValue value = (IntValue) expression.eval(state.getSymTable(), state.getHeap());
        if(!(value.getType() instanceof IntType))
            throw new MyException("Expression is not IntType");
        Integer location = state.getBarrier().getLocation();
        state.getSymTable().put(var, new IntValue(location));
        state.getBarrier().getBarrierTable().put(location, new Pair<>(value.getValue(), new ArrayList<>()));
        return null;
    }

    @Override
    public IDictionary<String, Type> typeCheck(IDictionary<String, Type> typeTable) throws MyException {
        if(!typeTable.get(var).equals(new IntType()))
            throw new MyException("Variable is not IntType");
        if(!expression.typeCheck(typeTable).equals(new IntType()))
            throw new MyException("Expression is not IntType");
        return typeTable;
    }

    public String toString() {
        return String.format("CyclicBarrier(%s, %s)", var, expression.toString());
    }
}
