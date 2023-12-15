import java.util.HashMap;
import java.util.Map;

class Node {
    public boolean end;
    public Map<Character, Node> edges;
    public Node() {
        this.end = false;
        this.edges = new HashMap<>();
    }
}

class Trie {
    private final Node root;

    public Trie() {
        root = new Node();
    }

    public void insert(String word) {
        Node node = root;
        for(Character c : word.toCharArray()) {
            if (!node.edges.containsKey(c)) {
                node.edges.put(c, new Node());
            }
            node = node.edges.get(c);
        }
        node.end = true;
    }

    public boolean search(String word) {
        Node node = root;
        for(Character c : word.toCharArray()) {
            if (!node.edges.containsKey(c)) {
                return false;
            }
            node = node.edges.get(c);
        }
        return node.end;
    }
}

public class Main {
    public static void main(String[] args) {
        Trie trie = new Trie();
        trie.insert("");
        trie.insert("abc");
        trie.insert("abcd");
        trie.insert("abcde");

        System.out.println(trie.search("def"));
    }
}