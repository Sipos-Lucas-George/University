package Model.Statements;

import Exceptions.MyException;
import Model.ADT.IDictionary;
import Model.Expressions.Expression;
import Model.ProgramState;
import Model.Types.Type;
import Model.Values.Value;

public class SwitchStatement implements IStatement{
    private final Expression expression;

    private final Expression expression1;

    private final IStatement statement1;

    private final Expression expression2;

    private final IStatement statement2;

    private final IStatement statement3;

    public SwitchStatement(Expression expression, Expression expression1, IStatement statement1, Expression expression2, IStatement statement2, IStatement statement3) {
        this.expression = expression;
        this.expression1 = expression1;
        this.statement1 = statement1;
        this.expression2 = expression2;
        this.statement2 = statement2;
        this.statement3 = statement3;
    }

    @Override
    public ProgramState execute(ProgramState state) throws MyException {
        Value value = expression.eval(state.getSymTable(), state.getHeap());
        Value value1 = expression1.eval(state.getSymTable(), state.getHeap());
        Value value2 = expression2.eval(state.getSymTable(), state.getHeap());

        if(value.equals(value1)){
            state.getExecStack().push(statement1);
        } else if (value.equals(value2)) {
            state.getExecStack().push(statement2);
        } else {
            state.getExecStack().push(statement3);
        }
        return null;
    }

    @Override
    public IDictionary<String, Type> typeCheck(IDictionary<String, Type> typeTable) throws MyException {
        if(!expression.typeCheck(typeTable).equals(expression1.typeCheck(typeTable)) || !expression.typeCheck(typeTable).equals(expression2.typeCheck(typeTable)))
            throw new MyException("Switch conditions are incorrect");
        statement1.typeCheck(typeTable.copy());
        statement2.typeCheck(typeTable.copy());
        statement3.typeCheck(typeTable.copy());
        return typeTable;
    }

    public String toString(){
        return String.format("Switch(%s)\n(case %s : %s)\n(case %s : %s)\n(default : %s)", expression.toString(), expression1.toString(), statement1.toString(), expression2.toString(), statement2.toString(), statement3.toString());
    }
}
