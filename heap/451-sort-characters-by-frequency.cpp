// Solution 1: sorting + heap
// N = length of string.
// Time complexity: O(NlogN) sorting + O(N) counting freq + O(NlogN) building res
// = O(NlogN)
// Space complexity: O(N)
class Solution {
public:
    string frequencySort(string s) {
        sort(s.begin(), s.end());
        priority_queue<pair<int, char>> Q;
        for(int i = 0, cnt = 0; i < (int)s.size(); i++) {
            cnt++;
            if ((i == (int)s.size() - 1) || (s[i] != s[i+1])) {
                Q.push(make_pair(cnt, s[i]));
                cnt = 0;   
            }    
        }
        
        string res = "";
        while(!Q.empty()) {
            res += string(Q.top().first, Q.top().second);
            Q.pop();
        }
        return res;
    }
};

// Solution 2: counting sort
// O(4N) = O(N) in time
// O(4N) = O(N) in space
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> M1;
        for(char c : s) M1[c]++;
        
        unordered_map<int, vector<char>> M2;
        vector<int> vals;
        for(auto p : M1) {
        	M2[p.second].push_back(p.first);
        	vals.push_back(p.second);
        }

        // Counting sort
        int mx = vals.size() ? *max_element(vals.begin(), vals.end()) : 0;
        vector<int> buckets(mx+1, 0);
        for(int val : vals) buckets[val]++;

        // Result
        string res = "";
        for(int i = mx; i >= 1; i--) {
        	if (buckets[i] > 0) {
        		for(char c : M2[i])
        			res += string(i, c);
        	}
        }
        return res;
    }
};

// Solution 3: couting sort v2
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for(char c : s) freq[c]++;
        
        // Counting sort
        vector<string> buckets(s.size()+1, "");
        for(auto& p : freq) {
            buckets[p.second].append(p.second, p.first);
        }
        
        // Res
        string res = "";
        for(int i = (int)s.size(); i >= 1; i--) {
            if (buckets[i] != "") {
                res.append(buckets[i]);
            }
        }
        return res;
    }
};
