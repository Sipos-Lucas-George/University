package Model.ADT;

import Exceptions.MyException;
import Model.Statements.IStatement;
import Model.Values.Value;

import java.util.List;
import java.util.Map;

public interface IProcedure {
    Map<String, Pair<List<String>, IStatement>> getContent();
    void setContent(Map<String, Pair<List<String>, IStatement>> newMap);
}
