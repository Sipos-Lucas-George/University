package Model.ADT;

import Exceptions.MyException;
import Model.Values.Value;

import java.util.Collection;
import java.util.Map;
import java.util.Set;

public interface IDictionary<K, V>{
    V get(K key);
    V put(K key, V value);
    boolean containsKey(K key);
    boolean containsValue(V value);
    void remove(K key) throws MyException;
    Collection<V> values();
    Set<K> keys();
    MyDictionary<K, V> cloneDict();
    Map<K, V> getContent();

    int size();
    Iterable<Map.Entry<K, V>> getAll();
    String toString();

}
