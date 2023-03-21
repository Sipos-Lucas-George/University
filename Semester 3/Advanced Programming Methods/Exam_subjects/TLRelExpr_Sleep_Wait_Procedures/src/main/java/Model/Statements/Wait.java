package Model.Statements;

import Exceptions.MyException;
import Model.ADT.IDictionary;
import Model.Expressions.*;
import Model.ProgramState;
import Model.Types.IntType;
import Model.Types.Type;
import Model.Values.IntValue;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Wait implements IStatement{
    private final Expression expression;
    private final static Lock lock = new ReentrantLock();

    public Wait(Expression expression) {
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState state) throws MyException {
        lock.lock();
        try {
            IntValue value = (IntValue) expression.eval(state.getSymTable().peek(), state.getHeap());
            if(value == null)
                throw new MyException("Value not found");
            if(value.getValue() != 0) {
                state.getExecStack().push(new Wait(new ArithExpression(
                        BinaryExpression.OPERATOR.SUBSTR,
                        expression,
                        new ValueExpression(new IntValue(1))
                )));
                state.getExecStack().push(new PrintStatement(expression));
            }
        } catch (MyException e) {
            System.out.println(e.toString());
        } finally {
            lock.unlock();
        }
        return null;
    }

    @Override
    public IDictionary<String, Type> typeCheck(IDictionary<String, Type> typeTable) throws MyException {
        if(!expression.typeCheck(typeTable).equals(new IntType()))
            throw new MyException("Expression is not IntType");
        return typeTable;
    }

    public String toString() {
        return String.format("Wait(%s)", expression);
    }
}
