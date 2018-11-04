vector<int> Solution::nextGreater(vector<int> &A) {
    stack<int> greaters;
    vector<int> ans;
    for(int i = (int)A.size() - 1; i >= 0; i--) {
        while(!greaters.empty() && (A[i] >= greaters.top())) {
            greaters.pop();
        }
        ans.push_back(greaters.empty() ? -1 : greaters.top());
        greaters.push(A[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
