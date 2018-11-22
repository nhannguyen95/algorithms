// Solution 1:
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0;
        int lastEnd = -1;
        for(int time : timeSeries) {
            ans += time + duration - max(time, lastEnd+1);
            lastEnd = time + duration - 1;
        }
        return ans;
    }
};
