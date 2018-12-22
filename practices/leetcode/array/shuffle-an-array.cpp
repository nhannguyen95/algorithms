// https://leetcode.com/problems/shuffle-an-array/

// Solution 1
class Solution {
private:
    vector<int> original;
    vector<int> ans;
    
    int random(int mn, int mx) {
        random_device rd;
        mt19937 rng(rd());
        uniform_int_distribution<int> uni(mn, mx);
        return uni(rng);
    }
public:
    Solution(vector<int> nums) {
        original = nums;
        ans = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        ans = original;
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i = 0; i < ans.size(); i++) {
            int j = random(i, (int)ans.size() - 1);
            swap(ans[i], ans[j]);
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
