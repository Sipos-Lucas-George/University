import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) throws IOException {
        A a = new A();
        List<String> cls = new ArrayList<>();
        List<String> voted = new ArrayList<>();
        File myObj1 = new File("D:\\University\\UNI\\Java\\Finals\\Filtering\\src\\class.in");
        Scanner myReader1 = new Scanner(myObj1);
        while (myReader1.hasNextLine()) {
            String data = myReader1.nextLine();
            cls.add(data);
        }
        File myObj2 = new File("D:\\University\\UNI\\Java\\Finals\\Filtering\\src\\voted.in");
        Scanner myReader2 = new Scanner(myObj2);
        while (myReader2.hasNextLine()) {
            String data = myReader2.nextLine();
            voted.add(data);
        }
        List<String> newVotes = cls.stream().filter(p -> a.func(p, voted)).toList();
//        BufferedWriter writer = new BufferedWriter(new FileWriter("final.in", true));
        FileWriter writer = new FileWriter("final.in");
        for (String line : newVotes) {
            writer.append(line).append("\n");
        }
    }
}