package Model.ADT;

import Exceptions.MyException;

import java.util.Iterator;
import java.util.Stack;
import java.util.function.Consumer;

public class MyStack<T> implements IStack<T> {
    public final Stack<T> stack;

    public MyStack(){
        this.stack = new Stack<>();
    }

    public MyStack(Stack<T> stack) {
        this.stack = stack;
    }

    @Override
    public void push(T v) {
        this.stack.push(v);
    }

    @Override
    public T pop() throws MyException {
        if(this.stack.isEmpty())
            throw new MyException("ERROR: Stack is empty and can't pop!");
        return this.stack.pop();
    }

    @Override
    public T top() throws MyException {
        if(this.stack.isEmpty())
            throw new MyException("ERROR: Stack is empty and can't pop!");
        return this.stack.peek();
    }

    @Override
    public boolean isEmpty() {
        return this.stack.isEmpty();
    }

    @Override
    public Stack<T> getStack() {
        return this.stack;
    }

    @Override
    public Iterator<T> iterator() {
        return this.stack.iterator();
    }

    @Override
    public void forEach(Consumer<? super T> action) {
        IStack.super.forEach(action);
    }
}
