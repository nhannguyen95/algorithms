// https://leetcode.com/problems/couples-holding-hands/

class Solution {
public:
    int findRoot(int u, vector<int>& lab) {
        return (lab[u] < 0) ? u : lab[u] = findRoot(lab[u], lab);
    }
    
    void merge(int u, int v, vector<int>& lab) {
        u = findRoot(u, lab);
        v = findRoot(v, lab);
        if (u == v) return;
        if (lab[u] > lab[v]) swap(u, v);
        lab[u] += lab[v];
        lab[v] = u;
    }
    
    int minSwapsCouples(vector<int>& row) {
        int n = row.size() / 2;
        vector<vector<int>> adj(n, vector<int>());
        
        vector<int> inVertex(2*n);
        for(int i = 0; i < 2*n; i++) inVertex[row[i]] = i / 2;
        
        vector<int> lab(n, -1);
        for(int i = 0; i < 2*n-1; i+=2)
            merge(inVertex[i], inVertex[i+1], lab);
        
        int ans = 0;
        set<int> seen;
        for(int i = 0; i < n; i++) {
            int root = findRoot(i, lab);
            if (seen.find(root) == seen.end()) {
                ans += abs(lab[root]) - 1;
                seen.insert(root);
            }
        }
        return ans;
    }
};
