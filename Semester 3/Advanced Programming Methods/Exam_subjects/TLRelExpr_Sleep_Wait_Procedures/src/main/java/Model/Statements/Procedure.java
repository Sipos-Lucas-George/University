package Model.Statements;

import Exceptions.MyException;
import Model.ADT.IDictionary;
import Model.ADT.Pair;
import Model.ProgramState;
import Model.Types.Type;

import java.util.List;

public class Procedure implements IStatement{
    private final String procName;
    private final List<String> args;
    private final IStatement statement;

    public Procedure(String procName, List<String> args, IStatement statement) {
        this.procName = procName;
        this.args = args;
        this.statement = statement;
    }

    @Override
    public ProgramState execute(ProgramState state) throws MyException {
        if(state.getProcedure().getContent().containsKey(procName))
            throw new MyException("Procedure name already exists");
        state.getProcedure().getContent().put(procName, new Pair<>(args, statement));
        return null;
    }

    @Override
    public IDictionary<String, Type> typeCheck(IDictionary<String, Type> typeTable) throws MyException {
        return typeTable;
    }

    @Override
    public String toString() {
        StringBuilder result = new StringBuilder(String.format("Procedure %s(", procName));
        for(int i = 0; i < args.size() - 1; ++i){
            result.append(args.get(i)).append(", ");
        }
        result.append(args.get(args.size() - 1)).append(String.format("){\n%s\n}", statement.toString()));
        return result.toString();
    }
}
