package Model.Expressions;

import Exceptions.MyException;
import Model.ADT.IDictionary;
import Model.ADT.IHeap;
import Model.Types.BoolType;
import Model.Types.Type;
import Model.Values.BoolValue;
import Model.Values.Value;

public class NotExpression implements Expression{
    private final Expression expression;

    public NotExpression(Expression expression) {
        this.expression = expression;
    }

    @Override
    public Value eval(IDictionary<String, Value> symTable, IHeap heap) throws MyException {
        BoolValue value = (BoolValue) expression.eval(symTable, heap);
        return new BoolValue(!value.getValue());
    }

    @Override
    public Type typeCheck(IDictionary<String, Type> typeTable) throws MyException {
        if(!expression.typeCheck(typeTable).equals(new BoolType()))
            throw new MyException("Expression is not BoolType");
        return new BoolType();
    }

    public String toString() {
        return String.format("Not(%s)", expression.toString());
    }
}
