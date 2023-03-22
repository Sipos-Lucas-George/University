package Model.Expressions;

import Exceptions.MyException;
import Model.ADT.IDictionary;
import Model.ADT.IHeap;
import Model.Types.IntType;
import Model.Types.Type;
import Model.Values.IntValue;
import Model.Values.Value;

public class MULExpression implements Expression{
    private final Expression expression1;
    private final Expression expression2;

    public MULExpression(Expression expression1, Expression expression2) {
        this.expression1 = expression1;
        this.expression2 = expression2;
    }

    @Override
    public Value eval(IDictionary<String, Value> symTable, IHeap heap) throws MyException {
        return new IntValue(
                ((IntValue)(new ArithExpression(
                        BinaryExpression.OPERATOR.SUBSTR,
                        new ArithExpression(
                                BinaryExpression.OPERATOR.MULT,
                                expression1,
                                expression2
                        ),
                        new ArithExpression(
                                BinaryExpression.OPERATOR.ADD,
                                expression1,
                                expression2
                        )
                )
            ).eval(symTable, heap)).getValue()
        );
    }

    @Override
    public Type typeCheck(IDictionary<String, Type> typeTable) throws MyException {
        if(!expression1.typeCheck(typeTable).equals(new IntType()) || !expression2.typeCheck(typeTable).equals(new IntType()))
            throw new MyException("Expression is not IntType");
        return new IntType();
    }

    public String toString() {
        return String.format("MUL(%s, %s)", expression1.toString(), expression2.toString());
    }
}
