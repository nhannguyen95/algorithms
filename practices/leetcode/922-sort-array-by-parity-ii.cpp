// Solution 1: O(1) in space, O(N) in time
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n = A.size();
        int even = 0;
        int odd = 1;
        for(int i = 0; i < n; i = min(even, odd)) {
            if (even >= n || odd >= n) break;
            
            if (A[i] % 2 == 0) {
                swap(A[i], A[even]);
                even += 2;
            } else {
                swap(A[i], A[odd]);
                odd += 2;
            }
        }
        return A;
    }
};
