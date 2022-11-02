package Model.Expressions;

import Exceptions.MyException;
import Model.ADT.IDictionary;
import Model.Types.Type;
import Model.Values.Value;

public interface Expression {
    Value eval(IDictionary<String, Value> symTable) throws MyException;
    Type typeCheck(IDictionary<String, Type> typeTable) throws MyException;
}
