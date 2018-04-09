// Solution 1: DSU
// N = number of nodes
// E = number of given edges
// O(N) in space
// O(E*alpha(N)) in space
// https://en.wikipedia.org/wiki/Disjoint-set_data_structure
class Solution {
public:
    int findRoot(int u, vector<int> & lab) {
        return (lab[u] < 0) ? u : lab[u] = findRoot(lab[u], lab);
    }

    void merge(int u, int v, vector<int> & lab) {
        u = findRoot(u, lab);
        v = findRoot(v, lab);
        if (u == v) return;
        if (lab[u] > lab[v])
            swap(u, v);
        lab[u] += lab[v];
        lab[v] = u;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> lab(1005, -1);

        int resu, resv;
        for(auto pair : edges) {
            int u = pair[0];
            int v = pair[1];

            if (findRoot(u, lab) == findRoot(v, lab)) {
                resu = u;
                resv = v;
            } else {
                merge(u, v, lab);
            }
        }
        return vector<int>({resu, resv});
    }
};
