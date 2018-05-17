# Solution 1: sorting + binary search
# N = number of intervals
# Time complexity: O(2NlogN)
# Space complexity: O(2N)
class Solution {
public:
    typedef pair<Interval, int> IdxIntervals;
    
    int lowerBound(vector<IdxIntervals> & sorteds, int from, int x) {
        int low = from;
        int high = (int)sorteds.size();
        while(low < high) {
            int mid = (low + high) / 2;
            if (sorteds[mid].first.start < x) low = mid + 1;
            else high = mid;
        }
        return (low < (int)sorteds.size()) ? low : -1;
    }
        
    vector<int> findRightInterval(vector<Interval>& intervals) {
        int n = (int)intervals.size();
        // Sort the intervals with ascending start point order.
        vector<IdxIntervals> sorteds;
        for(int i = 0; i < n; i++) 
            sorteds.push_back(make_pair(intervals[i], i));
        sort(sorteds.begin(), sorteds.end(), [](IdxIntervals & i1, IdxIntervals & i2) -> bool { return i1.first.start < i2.first.start;});
        
        // Binary search to find j interval
        vector<int> ans(n, -1);
        for(int i = 0; i < n; i++) {
            int j = lowerBound(sorteds, i+1, sorteds[i].first.end);
            ans[sorteds[i].second] = (j != -1) ? sorteds[j].second : j;
        }
        return ans;
    }
};

# Solution 2: cool implementation of #1
class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<int> ans;
        map<int, int> m;
        for(int i = 0; i < intervals.size(); i++)
            m[intervals[i].start] = i;
        for(auto i : intervals) {
            auto p = m.lower_bound(i.end);
            ans.push_back((p == m.end()) ? - 1 : (*p).second);
        }
        return ans;
    }
};
