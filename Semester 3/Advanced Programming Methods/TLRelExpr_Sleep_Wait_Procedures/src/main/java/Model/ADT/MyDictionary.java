package Model.ADT;

import Exceptions.MyException;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class MyDictionary<K, V> implements IDictionary<K, V>{
    private final Map<K, V> dictionary;

    public MyDictionary(){
        this.dictionary = new HashMap<>();
    }

    public MyDictionary(Map<K, V> dictionary) {
        this.dictionary = dictionary;
    }

    @Override
    public V get(K key) {
        synchronized (dictionary){
            return this.dictionary.get(key);
        }
    }

    @Override
    public V put(K key, V value) {
        synchronized (dictionary){
            return this.dictionary.put(key, value);
        }
    }

    @Override
    public boolean containsKey(K key) {
        synchronized (dictionary){
            return this.dictionary.containsKey(key);
        }
    }

    @Override
    public boolean containsValue(V value) {
        synchronized (dictionary){
            return this.dictionary.containsValue(value);
        }
    }

    @Override
    public void remove(K key) throws MyException {
        synchronized (dictionary){
            if(!this.dictionary.containsKey(key))
                throw new MyException("ERROR: Cannot remove non-existing key!");
            this.dictionary.remove(key);
        }
    }

    @Override
    public Collection<V> values() {
        synchronized (dictionary){
            return this.dictionary.values();
        }
    }

    @Override
    public Set<K> keys() {
        synchronized (dictionary){
            return this.dictionary.keySet();
        }
    }

    @Override
    public MyDictionary<K, V> copy() {
        MyDictionary<K, V> dict = new MyDictionary<>();
        for(K key : this.keys())
            dict.put(key, this.dictionary.get(key));
        return dict;
    }

    @Override
    public Map<K, V> getContent() {
        synchronized (dictionary){
            return dictionary;
        }
    }

    @Override
    public int size() {
        synchronized (dictionary){
            return this.dictionary.size();
        }
    }

    @Override
    public Iterable<Map.Entry<K, V>> getAll() {
        synchronized (dictionary){
            return this.dictionary.entrySet();
        }
    }
}
