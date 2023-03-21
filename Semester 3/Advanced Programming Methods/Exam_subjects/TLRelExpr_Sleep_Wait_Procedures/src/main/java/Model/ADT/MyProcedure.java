package Model.ADT;

import Model.Statements.IStatement;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class MyProcedure implements IProcedure{
    private Map<String, Pair<List<String>, IStatement>> procedureTable;

    public MyProcedure() {
        this.procedureTable = new HashMap<>();
    }

    @Override
    public Map<String, Pair<List<String>, IStatement>> getContent() {
        return this.procedureTable;
    }

    @Override
    public void setContent(Map<String, Pair<List<String>, IStatement>> newMap) {
        this.procedureTable = newMap;
    }
}
