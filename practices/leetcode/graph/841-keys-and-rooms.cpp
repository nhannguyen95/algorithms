// https://leetcode.com/problems/keys-and-rooms

// Solution 1: DFS
class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[u] = true;
        for(int v : adj[u])
            if (!visited[v])
                dfs(v, adj, visited);
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        
        dfs(0, rooms, visited);
        
        for(bool b : visited)
            if (!b) return false;
        return true;
    }
};
