package Model.ADT;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class MyBarrier implements IBarrier{
    private final Map<Integer, Pair<Integer, List<Integer>>> barrierTable;
    private final Integer location;
    private final static Lock lock = new ReentrantLock();

    public MyBarrier() {
        this.barrierTable = new HashMap<>();
        this.location = new Random().nextInt() % 10000;
    }

    @Override
    public Map<Integer, Pair<Integer, List<Integer>>> getBarrierTable() {
        return barrierTable;
    }

    @Override
    public Integer getLocation() {
        return location;
    }

    @Override
    public Lock getLock() {
        return lock;
    }

    @Override
    public boolean completed() {
        return barrierTable.get(location).first == barrierTable.get(location).second.size();
    }
}
