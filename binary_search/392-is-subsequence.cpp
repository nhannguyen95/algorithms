# Solution 1: 2 pointers
# N = len(S), M = len(T)
# O(1) in space
# O(max(S, T)) in time
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        while(i < s.size() && j < t.size()) {
            if (s[i] == t[j]) { i++; j++; }
            else j++;
        }
        return i == (int)s.size();
    }
};

# Solution 2: hash table + binary search
# Answer the follow up
class Solution {
public:
    int lower_bound(vector<int> & a, int x) {
        int low = 0;
        int high = a.size();
        while (low < high) {
            int mid = (low + high) >> 1;
            if (a[mid] < x) low = mid + 1;
            else high = mid;
        }
        return low;
    }
    
    bool isSubsequence(string s, string t) {
        unordered_map<char, vector<int>> pos;
        for(int i = 0; i < t.size(); i++)
            pos[t[i]].push_back(i);

        int nextPos = 0;
        for(char c : s) {
            if (pos.find(c) == pos.end()) return false;
            int i = lower_bound(pos[c], nextPos);
            if (i == pos[c].size()) return false;
            nextPos = pos[c][i] + 1;
        }
        return true;
    }
};
