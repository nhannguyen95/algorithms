// O(N) in space
// O(2N) = O(N) in time
vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> s;
    vector<int> ans;
    for(int i = 0; i < (int)A.size(); i++) {
        while(!s.empty() && s.top() >= A[i]) {
            s.pop();
        }

        ans.push_back(s.empty() ? -1 : s.top());
        s.push(A[i]);
    }

    return ans;
}
