import java.util.ArrayList;
import java.util.List;

public class Main {

    private static List<String> split(String s, String delim) {
        List<String> tokens = new ArrayList<>();
        int last = 0;
        for(int next; (next = s.indexOf(delim, last)) != -1;) {
            if (last < next) {
                tokens.add(s.substring(last, next));
            }
            last = next + delim.length();
        }
        if (last < s.length()) {
            tokens.add(s.substring(last));
        }
        return tokens;
    }

    public static void main(String[] args) {
    }
}