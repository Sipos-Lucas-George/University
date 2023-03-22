package Model.Statements;

import Exceptions.MyException;
import Model.ADT.IDictionary;
import Model.ADT.IStack;
import Model.Expressions.BinaryExpression;
import Model.Expressions.Expression;
import Model.Expressions.RelationalExpression;
import Model.Expressions.VariableExpression;
import Model.ProgramState;
import Model.Types.IntType;
import Model.Types.Type;
import Model.Values.Value;

public class ForStatement implements IStatement{
    private final String value;
    private final Expression expression1;
    private final Expression expression2;
    private final Expression expression3;
    private final IStatement statement;

    public ForStatement(String value, Expression expression1, Expression expression2, Expression expression3, IStatement statement) {
        this.value = value;
        this.expression1 = expression1;
        this.expression2 = expression2;
        this.expression3 = expression3;
        this.statement = statement;
    }


    @Override
    public ProgramState execute(ProgramState state) throws MyException {
        IStack<IStatement> execStack = state.getExecStack();
        execStack.push(new WhileStatement(
                new RelationalExpression(BinaryExpression.OPERATOR.LESS, new VariableExpression(value), expression2),
                new CompStatement(statement, new AssStatement(value, expression3))));
        execStack.push(new AssStatement(value, expression1));
        execStack.push(new DeclarationStatement(value, new IntType()));
        return null;
    }

    @Override
    public IDictionary<String, Type> typeCheck(IDictionary<String, Type> typeTable) throws MyException {
        if(!expression1.typeCheck(typeTable).equals(new IntType()) || !expression2.typeCheck(typeTable).equals(new IntType()) || !expression3.typeCheck(typeTable).equals(new IntType()))
            throw new MyException("One of the expressions is not an IntType");
        return typeTable;
    }

    public String toString() {
        return String.format("For(%s = %s; %s < %s; %s = %s){\n\t%s\n}", value, expression1.toString(), value, expression2.toString(), value, expression3.toString(), statement.toString());
    }
}
