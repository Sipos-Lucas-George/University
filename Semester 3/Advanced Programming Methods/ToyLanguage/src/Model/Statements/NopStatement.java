package Model.Statements;

import Exceptions.MyException;
import Model.ProgramState;

public class NopStatement implements IStatement{

    @Override
    public ProgramState execute(ProgramState state) throws MyException {
        return null;
    }

    public String toString(){
        return "NopStatement";
    }
}
