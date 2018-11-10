// https://leetcode.com/problems/baseball-game/

// Solution 1: Stack
// N = len(ops)
// O(N*average_number_of_digits_of_point) in time in worst case
// O(N) in space in worst case
class Solution {
public:
    int calPoints(vector<string>& ops) {
        int ans = 0;
        stack<int> points;
        for(auto & op : ops) {
            if (!op.compare("+")) {
                int pre1 = points.top(); points.pop();
                int pre2 = points.top();
                int point = pre1 + pre2;
                
                ans += point;
                points.push(pre1);
                points.push(point);
            } else if (!op.compare("D")) {
                int pre = points.top();
                int point = pre * 2;
                
                ans += point;
                points.push(point);
            } else if (!op.compare("C")) {
                int pre = points.top();
                points.pop();
                
                ans -= pre;
            } else {
                int point = stoi(op);
                ans += point;
                points.push(point);
            }
        }
        return ans;
    }
};
