/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

/* First solution
 * O(NlogN) time, O(N) space
 */
bool isOverlap(const Interval & interval1, const Interval & interval2) {
    return !((interval1.end < interval2.start) ||
             (interval1.start > interval2.end));
}

// interval1 and interval2 must be overlapped.
Interval mergeInterval(const Interval & interval1, const Interval & interval2) {
    return Interval(min(interval1.start, interval2.start),
                    max(interval1.end, interval2.end));
}

// Return true if interval1 comes ahead of interval2 in the array.
bool comp(Interval interval1, Interval interval2) {
    return interval1.start < interval2.start;
}

vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    Interval mergedInterval(newInterval.start, newInterval.end);
    vector<Interval> ans;
    for(int i = 0; i < (int) intervals.size(); i++) {
        if (isOverlap(intervals[i], mergedInterval)) {
            mergedInterval = mergeInterval(intervals[i], mergedInterval);
        } else {
            ans.push_back(intervals[i]);
        }
    }
    ans.push_back(mergedInterval);
    sort(ans.begin(), ans.end(), comp);
    return ans;
}
