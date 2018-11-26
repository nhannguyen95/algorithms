class MyCalendarThree {
private:
    map<int, int> M;
    
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        M[start]++;
        M[end]--;
        
        int ans = 0, sum = 0;
        for(auto it = M.begin(); it != M.end(); it++) {
            sum += it->second;
            ans = max(ans, sum);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */
