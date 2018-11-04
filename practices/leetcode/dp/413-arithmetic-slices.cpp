// Solution 1: dp
// O(N) in time and space
class Solution {
public:
    struct HASH {   
        size_t operator()(const pair<int, int> & x) const {
            return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
        }
    };
    
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        unordered_map<pair<int, int>, int, HASH> M;
        int res = 0;
        for(int i = 1; i < A.size(); i++) {
            int d = A[i] - A[i-1];
            if (i == 1) M[make_pair(1, d)] = 1;
            else {
                if (A[i-1] - A[i-2] != d) continue;
                M[make_pair(i, d)] = 2 + M[make_pair(i-2, d)];
                res += max(0, M[make_pair(i, d)] - 1);
            }
        }
        return res;
    }
};

// Solution 2: better dp
// O(N) in time, O(1) in space
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if (n < 3) return 0;
        int dp = 0, sum = 0;
        for(int i = 2; i < n; i++) {
            if (A[i] - A[i-1] == A[i-1]-A[i-2]) {
                dp++;
                sum += dp;
            } else {
                dp = 0;
            }
        }
        return sum;
    }
};
