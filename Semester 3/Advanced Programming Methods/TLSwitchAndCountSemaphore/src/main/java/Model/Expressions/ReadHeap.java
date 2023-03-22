package Model.Expressions;

import Exceptions.MyException;
import Model.ADT.IDictionary;
import Model.ADT.IHeap;
import Model.Types.RefType;
import Model.Types.Type;
import Model.Values.RefValue;
import Model.Values.Value;

public class ReadHeap implements Expression{
    private final Expression expression;

    public ReadHeap(Expression expression) {
        this.expression = expression;
    }

    @Override
    public Value eval(IDictionary<String, Value> symTable, IHeap heap) throws MyException {
        Value evaluated = expression.eval(symTable, heap);
        if(!(evaluated instanceof RefValue refValue))
            throw new MyException(String.format("ERROR: %s is not of RefType", evaluated));
        return heap.get(refValue.getAddress());
    }

    @Override
    public Type typeCheck(IDictionary<String, Type> typeTable) throws MyException {
        Type type = expression.typeCheck(typeTable);
        if(type instanceof RefType reference)
            return reference.getInner();
        else
            throw new MyException("The ReadHeap argument is not a RefType");
    }

    public String toString(){
        return String.format("ReadHeap{%s}", expression);
    }
}
