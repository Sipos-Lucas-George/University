package Model.Types;

import Model.Values.StringValue;
import Model.Values.Value;

public class StringType implements Type {
    @Override
    public boolean equals(Type other) {
        return other instanceof StringType;
    }

    @Override
    public Value getDefault() {
        return new StringValue("");
    }

    public String toString() {
        return "string";
    }
}
