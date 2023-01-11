package Model.Values;

import Model.Types.BoolType;
import Model.Types.Type;

public class BoolValue implements Value{
    private final boolean val;

    public BoolValue(boolean val) {
        this.val = val;
    }

    public boolean getValue(){
        return val;
    }

    @Override
    public String toString(){
        return val ? "true" : "false";
    }

    @Override
    public boolean equals(Object obj) {
        if (!(obj instanceof BoolValue newVal))
            return false;
        return val == newVal.val;
    }

    @Override
    public Type getType() {
        return new BoolType();
    }
}
