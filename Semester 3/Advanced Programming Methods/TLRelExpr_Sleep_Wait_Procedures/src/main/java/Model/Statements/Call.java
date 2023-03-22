package Model.Statements;

import Exceptions.MyException;
import Model.ADT.IDictionary;
import Model.Expressions.Expression;
import Model.ProgramState;
import Model.Types.Type;
import Model.Values.Value;

import java.util.List;

public class Call implements IStatement{
    private final String procName;
    private final List<Expression> args;

    public Call(String procName, List<Expression> args) {
        this.procName = procName;
        this.args = args;
    }

    @Override
    public ProgramState execute(ProgramState state) throws MyException {
        if(!state.getProcedure().getContent().containsKey(procName))
            throw new MyException("Procedure not in ProcedureTable");
        if(state.getProcedure().getContent().get(procName).first.size() != args.size())
            throw new MyException(String.format("Too many/not enough parameters, expected %d", state.getProcedure().getContent().get(procName).first.size()));
        state.getSymTable().push(state.getSymTable().peek().copy());
        int i = 0;
        for(String arg : state.getProcedure().getContent().get(procName).first) {
            Value value = args.get(i).eval(state.getSymTable().peek(), state.getHeap());
            state.getSymTable().peek().put(state.getProcedure().getContent().get(procName).first.get(i++), value);
        }
        state.getExecStack().push(new Return());
        state.getExecStack().push(state.getProcedure().getContent().get(procName).second);
        return null;
    }

    @Override
    public IDictionary<String, Type> typeCheck(IDictionary<String, Type> typeTable) throws MyException {
        return typeTable;
    }

    @Override
    public String toString() {
        StringBuilder result = new StringBuilder(String.format("Call %s(", procName));
        for(int i = 0; i < args.size() - 1; ++i){
            result.append(args.get(i)).append(", ");
        }
        result.append(args.get(args.size() - 1)).append(")");
        return result.toString();
    }
}
