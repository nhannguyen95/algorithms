// https://leetcode.com/problems/rabbits-in-forest/

// Solution 1
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int, int> m;
        for(int answer : answers)
            m[answer+1]++;
        
        int ans = 0;
        for(auto it = m.begin(); it != m.end(); it++) {
            int n = (it->second / it->first) + ((it->second % it->first) != 0);
            ans += n * it->first;
        }
        return ans;
    }
};
