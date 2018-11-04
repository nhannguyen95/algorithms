// O(size(A)) in time
// O(B) in space
vector<int> Solution::findPerm(const string A, int B) {
    assert(B == A.size() + 1);
    vector<int> ans;
    int mn = 1, mx = B;
    for(char c : A) {
        if (c == 'I') {
            ans.push_back(mn);
            mn++;
        } else {
            ans.push_back(mx);
            mx--;
        }
    }
    ans.push_back(mn);
    return ans;
}
