package Model.Statements;

import Exceptions.MyException;
import Model.ADT.IDictionary;
import Model.Expressions.Expression;
import Model.Expressions.VariableExpression;
import Model.ProgramState;
import Model.Types.BoolType;
import Model.Types.Type;
import Model.Values.Value;

public class CondAss implements IStatement {
    private final String var;
    private final Expression expression1;
    private final Expression expression2;
    private final Expression expression3;

    public CondAss(String var, Expression expression1, Expression expression2, Expression expression3) {
        this.var = var;
        this.expression1 = expression1;
        this.expression2 = expression2;
        this.expression3 = expression3;
    }

    @Override
    public ProgramState execute(ProgramState state) throws MyException {
        state.getExecStack().push(new IfStatement(
                expression1,
                new AssStatement(var, expression2),
                new AssStatement(var, expression3)
        ));
        return null;
    }

    @Override
    public IDictionary<String, Type> typeCheck(IDictionary<String, Type> typeTable) throws MyException {
        if(!expression1.typeCheck(typeTable).equals(new BoolType()))
            throw new MyException("First expression is not BoolType");
        if(!typeTable.get(var).equals(expression2.typeCheck(typeTable)) || !typeTable.get(var).equals(expression3.typeCheck(typeTable)))
            throw new MyException("Expression 2 and 3 are not the same as variable type");
        return typeTable;
    }

    public String toString() {
        return String.format("%s = %s ? %s : %s", var, expression1.toString(), expression2.toString(), expression3.toString());
    }
}
