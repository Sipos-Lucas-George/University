package Model.Statements;

import Exceptions.MyException;
import Model.ADT.IDictionary;
import Model.ProgramState;
import Model.Types.Type;
import Model.Values.Value;

public class DeclarationStatement implements IStatement{
    private final String name;
    private final Type type;

    public DeclarationStatement(String name, Type type) {
        this.name = name;
        this.type = type;
    }

    @Override
    public ProgramState execute(ProgramState state) throws MyException {
        IDictionary<String, Value> symTable = state.getSymTable().peek();
        if(symTable.containsKey(name)){
            throw new MyException(String.format("Error: %s is already declared.", name));
        }
        symTable.put(name, type.getDefault());
        return null;
    }

    @Override
    public IDictionary<String, Type> typeCheck(IDictionary<String, Type> typeTable) throws MyException {
        typeTable.put(name, type);
        return typeTable;
    }

    public String toString(){
        return String.format("Declaration {%s: %s}", name, type.toString());
    }
}
