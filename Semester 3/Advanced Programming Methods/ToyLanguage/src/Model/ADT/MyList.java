package Model.ADT;

import Exceptions.MyException;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.function.Consumer;

public class MyList<T> implements IList<T> {
    private final ArrayList<T> list;

    public MyList() {
        this.list = new ArrayList<>();
    }

    public MyList(ArrayList<T> _list) {
        list = _list;
    }

    @Override
    public void add(T val) {
        this.list.add(val);
    }

    @Override
    public void remove(T elem) throws MyException {
        if(!list.remove(elem))
            throw new MyException("ERROR: Can't remove element from list!");
    }

    @Override
    public void remove(int index) throws MyException {
        if(index >= list.size() || index < 0)
            throw new MyException("ERROR: Position out of bound when trying to remove from list!");
    }

    @Override
    public T get(int index) {
        return list.get(index);
    }

    @Override
    public boolean isEmpty() {
        return this.list.isEmpty();
    }

    @Override
    public ArrayList<T> getList() {
        return list;
    }

    @Override
    public Iterator<T> iterator() {
        return list.listIterator();
    }

    @Override
    public void forEach(Consumer<? super T> action) {
        IList.super.forEach(action);
    }

    @Override
    public String toString(){
        return list.toString();
    }
}
