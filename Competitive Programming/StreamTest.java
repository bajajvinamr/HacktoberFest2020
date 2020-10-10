import java.util.ArrayList;
import java.util.List;

public class StreamTest {
    /**
     * Simple program to see Java8 streams in action
     * Takes a list of String values and outputs a String post data Manipulation
     */

    public List<String> getArrayList() {
        List<String> a = new ArrayList<>();
        a.add("Hema");
        a.add("Rekha");
        a.add("Jaya");
        a.add("Sushma");
        a.add("Sabki");
        a.add("Pasand");
        a.add("Nirma");
        a.add("Nirma");

        return a;

    }


    public static void main(String[] args) {
        StreamTest t = new StreamTest();
        List<String> a = t.getArrayList();

        String f = a.stream()
                .distinct()
                .filter(s -> s.contains("m"))
                .map(s -> (s + "Hi"))
                .peek(System.out::println)
                .reduce((s1, s2) -> (s1 + s2)).orElseGet(() -> "0");

        System.out.println("Final output:" + f);
    }

}
