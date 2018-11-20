// Solution 1: DFS
// Time complexity: O(V + E + VlogV)
// Space complexity: O(V + D), where D is the maximum length of any path in the graph.
class Solution {
public:
    // DFS on DAG 
    int getImportance(const vector<Employee*> & employees,
                      int id,
                      map<int, int> & pos) {
        int u = pos[id];
        int importance = employees[u]->importance;
        for(int sid : employees[u]->subordinates) {
            importance += getImportance(employees, sid, pos);
        }
        return importance;
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        map<int, int> pos;
        for(int i = 0; i < employees.size(); i++)
            pos[employees[i]->id] = i;
        
        return getImportance(employees, id, pos);
    }
};
