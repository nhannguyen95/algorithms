// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

class Solution {
public:
    int findRoot(int u, vector<int>& lab) {
        return lab[u] < 0 ? u : lab[u] = findRoot(lab[u], lab);
    }
        
    void merge(int u, int v, vector<int>& lab) {
        u = findRoot(u, lab);
        v = findRoot(v, lab);
        if (u == v) return;
        if (lab[u] > lab[v]) swap(u, v);
        lab[u] += lab[v];
        lab[v] = u;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        
        vector<int> lab(20000, -1);
        for(vector<int>& stone : stones) {
            merge(stone[0], stone[1] + 10000, lab);
        }
        
        set<int> seen;
        for(vector<int>& stone : stones)
            seen.insert(findRoot(stone[0], lab));
        return n - seen.size();
    }
    
    // bool isAdj(vector<int>& s1, vector<int>& s2) {
    //     return s1[0] == s2[0] || s1[1] == s2[1];    
    // }
    
//     int dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
//         visited[u] = true;
//         int ans = 0;
//         for(int v : adj[u]) {
//             if (!visited[v]) {
//                 ans += dfs(v, adj, visited);
//             }
//         }
//         return ans + 1;
//     }

    
//     int removeStones(vector<vector<int>>& stones) {
//         int n = stones.size();
        
//         vector<vector<int>> adj(n, vector<int>());
//         for(int i = 0; i < n-1; i++)
//             for(int j = i+1; j < n; j++) {
//                 if (isAdj(stones[i], stones[j])) {
//                     adj[i].push_back(j);
//                     adj[j].push_back(i);
//                 }
//             }
        
//         vector<bool> visited(n, false);
//         int ans = 0;
//         for(int i = 0; i < n; i++) {
//             if (!visited[i]) {
//                 ans += (dfs(i, adj, visited) - 1);
//             }
//         }
//         return ans;
//     }
};
   
