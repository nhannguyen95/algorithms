// https://leetcode.com/problems/all-paths-from-source-to-target/

// Solution 1: DFS
// Since we use adj list, Omega(V + E) in time, this is just a lowerbound
// K = number of path from 0 -> V - 1 => O(V + E + K * len(path))
// O(K * len(path)) in space
class Solution {
public:
    void dfs(int u, int des, 
             vector<vector<int>>& graph,
             vector<int> & path,
             vector<vector<int>> & paths) {
        path.push_back(u);
        
        if (u == des) {
            paths.push_back(path);
        } else {
            for(int & v : graph[u])
                dfs(v, des, graph, path, paths);
        }
        
        path.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path;
        dfs(0, graph.size() - 1, graph, path, paths);
        return paths;
    }
};
