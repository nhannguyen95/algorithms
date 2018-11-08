// https://leetcode.com/problems/number-of-recent-calls

// Solution 1: O(3000) in space, O(2N) in time, N = len(inputs)
class RecentCounter {
private:
    queue<int> Q;
    
public:
    RecentCounter() {
        this->Q = queue<int>();
    }  
    
    int ping(int t) {
        Q.push(t);
        while(!Q.empty() && Q.front() < t - 3000) {
            Q.pop();
        }
        return (int)Q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
