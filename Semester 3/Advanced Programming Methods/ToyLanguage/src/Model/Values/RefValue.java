package Model.Values;

import Model.Types.RefType;
import Model.Types.Type;

public class RefValue implements Value{
    private final String address;
    private final Type locationType;

    public RefValue(String address, Type locationType) {
        this.address = address;
        this.locationType = locationType;
    }

    public String getAddress() {
        return address;
    }

    public Type getLocationType() {
        return locationType;
    }

    @Override
    public Type getType() {
        return new RefType(locationType);
    }

    public String toString(){
        return String.format("ReferenceValue{%s in %s}", address, locationType);
    }
}
