/*
int[] d = new int[n + 1];
Arrays.fill(d, Integer.MAX_VALUE);
d[src] = 0;

NavigableSet<Pair<Integer, Integer>> nodes = new TreeSet<>(
    (node1, node2) -> {
        int temp = node1.getKey().compareTo(node2.getKey());
        if (temp != 0) {
            return temp;
        }
        return node1.getValue().compareTo(node2.getValue());
    }
);
for(int u = 1; u <= n; u++) {
    nodes.add(new Pair(d[u], u));
}

while(!nodes.isEmpty()) {
    var node = nodes.pollFirst();
    int du = node.getKey();
    int u = node.getValue();
    for(var edge : adj.get(u)) {
        int v = edge.getKey();
        int w = edge.getValue();
        if (du + w < d[v]) {
            nodes.remove(new Pair(d[v], v));
            d[v] = du + w;
            nodes.add(new Pair(d[v], v));
        }
    }
}
*/