import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        List<Integer> integers1 = Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
        System.out.println(integers1.stream()
                .filter(p -> p % 3 == 0 || p % 2 == 0)
                .map(p -> String.format("A%dB", p + 1))
                .collect(Collectors.joining()));

        List<Integer> integers2 = Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
        System.out.println(List.of(integers2.stream()
                .filter(p -> p % 4 != 0)
                .mapToInt(p -> p + 1)
                .sum() % 2));
    }


}