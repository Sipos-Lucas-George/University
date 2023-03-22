package Model.Statements;

import Exceptions.MyException;
import Model.ADT.IDictionary;
import Model.Expressions.Expression;
import Model.ProgramState;
import Model.Types.Type;
import Model.Values.Value;

public class AssStatement implements IStatement{
    private final String key;
    private final Expression expression;

    public AssStatement(String key, Expression expression) {
        this.key = key;
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState state) throws MyException {
        IDictionary<String, Value> symTable = state.getSymTable().peek();
        Type type = symTable.get(key).getType();
        Value value = expression.eval(symTable, state.getHeap());
        if (!value.getType().equals(type))
            throw new MyException(String.format("ERROR: %s is not compatible with %s", value.toString(), type.toString()));
        if (!symTable.containsKey(key))
            throw new MyException(String.format("ERROR: %s does not exist in symTable", key));
        symTable.put(key, value);
        return null;
    }

    @Override
    public IDictionary<String, Type> typeCheck(IDictionary<String, Type> typeTable) throws MyException {
        if(!typeTable.get(key).equals(expression.typeCheck(typeTable)))
            throw new MyException("Assigment: right hand side and left hand side have different types");
        return typeTable;
    }

    public String toString(){
        return String.format("Assigment{%s = %s}", key, expression.toString());
    }
}
