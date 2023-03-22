package Model.Statements;

import Exceptions.MyException;
import Model.ADT.IDictionary;
import Model.Expressions.*;
import Model.ProgramState;
import Model.Types.BoolType;
import Model.Types.Type;
import Model.Values.BoolValue;
import Model.Values.IntValue;
import gui.toylanguagegui.StageLoader;

public class RepeatUntil implements IStatement {
    private final IStatement statement;
    private final Expression expression;

    public RepeatUntil(IStatement statement, Expression expression) {
        this.statement = statement;
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState state) throws MyException {
        state.getExecStack().push(new WhileStatement(new NotExpression(expression), statement));
        state.getExecStack().push(statement);
        return null;
    }

    @Override
    public IDictionary<String, Type> typeCheck(IDictionary<String, Type> typeTable) throws MyException {
        if(!expression.typeCheck(typeTable).equals(new BoolType()))
            throw new MyException("Expression is not BoolType");
        return typeTable;
    }

    public String toString() {
        return String.format("Repeat\n%s\nUntil(%s)", statement.toString(), expression.toString());
    }
}
