// Solution 1: heap
// Original: http://vn.spoj.com/problems/KMIN/
// N = size(nums2)
// Time complexity: O(N) + O(KlogN)
// Space complexity: O(N)
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    	typedef pair<int, int> ii;
        typedef pair<long long, ii> lii;
        priority_queue<lii, vector<lii>, greater<lii>> Q;
        for(int j = 0; j < (int)nums2.size(); j++)
            if (nums1.size())
        	    Q.push(make_pair(nums1[0] + nums2[j], make_pair(0, j)));

        vector<ii> pairs;
        while(k-- && !Q.empty()) {
        	int i = Q.top().second.first;
        	int j = Q.top().second.second;
        	pairs.push_back(make_pair(nums1[i], nums2[j]));
        	Q.pop();
        	if (i < nums1.size() - 1) {
        		i++;
        		Q.push(make_pair(nums1[i] + nums2[j], make_pair(i, j)));
        	}
        }
        return pairs;
    }
};
