import java.util.List;

public class A {
    public boolean func(String a, List<String> b) {
        String[] d = a.split("\\s+");
        for (String c : b) {
            int cnt = 0;
            for(String inList : d){
                if(c.contains(inList))
                    cnt++;
            }
            if(cnt > 1)
                return false;
        }
        return true;
    }
}
