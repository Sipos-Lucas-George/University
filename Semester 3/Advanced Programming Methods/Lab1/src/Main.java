import java.util.Scanner;

class Group{
    protected static int objectsInGroup = 0;

    public void print(){
        System.out.println("There are " + objectsInGroup + " objects in this group!");
    }
}

class Person extends Group {
    private String name;
    private static int numberOfPeople = 0;

    public Person(String name){
        try{
            if(name.length() < 3)
                throw new Exception();
            this.name = name;
            objectsInGroup++;
            numberOfPeople++;
        } catch (Exception e) {
            System.out.println("The name should have at least 3 letters!!!");
        }
    }

    public String getName() {
        return name;
    }

    @Override
    public void print(){
        System.out.println("There are " + numberOfPeople + " people in this group!");
    }
}

public class Main {
    public static void main(String[] args) {
//        Scanner scanner = new Scanner(System.in);
//
//        System.out.println("Number of numbers: ");
//        int n = scanner.nextInt();
//        int sum = 0;
//        for(int i = 0; i < n; ++i){
//            sum += scanner.nextInt();
//        }
//        scanner.close();
//        System.out.println("The average is: " + sum/n);
        Person p0 = new Person("");
        Person p1 = new Person("ab");
        Person p2 = new Person("Lucas");
        Person p3 = new Person("Sicoe");

        p2.print();
        new Group().print();
    }
}