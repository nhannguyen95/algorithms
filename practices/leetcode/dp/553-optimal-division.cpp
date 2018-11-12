// https://leetcode.com/problems/optimal-division/

// Solution 1: Top down dp without memoization
// Time complexity:
// - T(1) = 1
//   T(N) = 2*sum[k=1..(N-1)] T(k) + O(N) (O(N) for string concatenation)
//=> T(N-1) = 2*sum[k=1..(N-2)] T(k) + O(N)
//=> T(N) - T(N-1) = T(N-1) + O(N)
//=> T(N) = 2T(N-1) + O(N)
//=> T(N) = (2^N)
//
// Space complexity:
// - Depth of the recursion tree: O(N)
// - Notice that we don't need to take into account the memory for saving the result string here.
//   Why? becase the result string of a node in the tree will be destroyed when the program exits
//   the recursion call of its parent.
class Solution {
public:
    struct Result {
        double mx;
        double mn;
        string reprMax;
        string reprMin;
        Result() : mx(0), mn(numeric_limits<double>::max()), reprMax(""), reprMin("") {}
        Result(double mx, double mn, string reprMax, string reprMin)
            : mx(mx), mn(mn), reprMax(reprMax), reprMin(reprMin) {}
    };

    Result solve(vector<int>& nums, int l, int r) {
        if (l == r) return Result(nums[l], nums[l], to_string(nums[l]), to_string(nums[l]));

        Result ans;
        for(int i = l; i < r; i++) {
            Result nume = solve(nums, l, i);
            Result deno = solve(nums, i+1, r);
            double lesser = nume.mn / deno.mx;
            double greater = nume.mx / deno.mn;

            // Find min
            if (lesser < ans.mn) {
                ans.mn = lesser;

                if (i+1 == r) {
                    ans.reprMin = nume.reprMin + "/" + deno.reprMax;
                } else {
                    ans.reprMin = nume.reprMin + "/" + "(" + deno.reprMax + ")";
                }
            }

            // Find max
            if (greater > ans.mx) {
                ans.mx = greater;

                if (i+1 == r) {
                    ans.reprMax = nume.reprMax + "/" + deno.reprMin;
                } else {
                    ans.reprMax = nume.reprMax + "/" + "(" + deno.reprMin + ")";
                }
            }
        }
        return ans;
    }

    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return to_string(nums[0]);
        return solve(nums, 0, n-1).reprMax;
    }
};

// Solution 2: using memoi
// TODO
// Time complexity: O(N^3) (involve the time for concatenation of each dp[i][j])
// Space complexity: O(N^3) as well
