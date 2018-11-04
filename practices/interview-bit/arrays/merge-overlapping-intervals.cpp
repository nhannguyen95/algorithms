/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

// N = number of intervals
// O(NlogN) in time, O(N) in space

// Return true if i1 comes ahead of i2 in the array
bool comp(Interval i1, Interval i2) {
    return (i1.start < i2.start) ||
           ((i1.start == i2.start) && (i1.end < i2.end));
}

bool isOverlap(const Interval & i1, const Interval & i2) {
    return !((i1.end < i2.start) ||
             (i1.start > i2.end));
}

// i1 and i2 must be overlapped
Interval mergeInterval(const Interval & i1, const Interval & i2) {
    return Interval(min(i1.start, i2.start),
                    max(i1.end, i2.end));
}

vector<Interval> Solution::merge(vector<Interval> &A) {
    sort(A.begin(), A.end(), comp);
    vector<Interval> ans;
    int i = 0;
    while(i < (int) A.size()) {
        Interval mergedInterval = A[i];
        while(i < (int) A.size() - 1 && isOverlap(mergedInterval, A[i + 1])) {
            mergedInterval = mergeInterval(mergedInterval, A[i + 1]);
            i++;
        }
        ans.push_back(mergedInterval);
        i++;
    }
    return ans;
}
