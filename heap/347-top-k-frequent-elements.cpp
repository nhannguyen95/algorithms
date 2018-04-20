// Solution 1: heap
// Time complexity: O(N) + O(Nu logK) + O(K)
// Space complexity: O(Nu) + O(K) + O(K)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Count frequency, O(N)
        unordered_map<int, int> freq;
        for(int num : nums) freq[num]++;
        
        // Nu = number of unique element
        // Push frequency into heap, O(NulogK)
        typedef pair<int, int> ii;
        priority_queue<ii, vector<ii>, greater<ii>> Q;
        for(auto& p : freq) {
            Q.push(make_pair(p.second, p.first));
            if (Q.size() > k) Q.pop();
        }
        
        // Result, O(K)
        vector<int> res;
        while(!Q.empty()) {
            res.push_back(Q.top().second);
            Q.pop();
        }
        return res;
    }
};

// Solution 2: counting sort
// I don't really like this idea that much
