package Model.Values;

import Model.Types.IntType;
import Model.Types.Type;

public class IntValue implements Value{
    private final int val;

    public IntValue(int val) {
        this.val = val;
    }

    public int getValue(){
        return val;
    }

    @Override
    public Type getType() {
        return new IntType();
    }

    @Override
    public String toString(){
        return String.format("%d", this.val);
    }

    @Override
    public boolean equals(Object obj){
        if(!(obj instanceof IntValue newInt))
            return false;
        return this.val == newInt.val;
    }
}
