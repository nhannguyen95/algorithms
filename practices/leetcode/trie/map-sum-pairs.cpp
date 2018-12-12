// https://leetcode.com/problems/map-sum-pairs/solution/

// Solution 1: Brute force with binary search tree (map)
// Time complexity: K = average of key (prefix), N = number of keys in the map
// - insert: O(logN)
// - sum: O(logN + N * P)
class MapSum {
private:
    map<string, int> m;
    
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        m[key] = val;    
    }
    
    int sum(string prefix) {
        auto it = m.lower_bound(prefix);
        int ans = 0;
        while(it != m.end() && (it->first).compare(0, prefix.size(), prefix) == 0) {
            ans += it->second;
            it++;
        }
        return ans;
    }
};
