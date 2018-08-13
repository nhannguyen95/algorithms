// Solution 1: 2 pointers
// O(1) in space, O(N) in time
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while(i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) return vector<int>({i+1, j+1});
            if (sum < target) i++;
            else j--;
        }
        return vector<int>({0, 0});
    }
};

// Solution 2: A bit of improve using binary search
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while(i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) return vector<int>({i+1, j+1});
            if (sum < target) {
                int old_i = i;
                i = lower_bound(numbers.begin() + i, numbers.begin() + j, target - numbers[j] + 1) 
                    - numbers.begin() - 1;
                if (i == old_i) i++;
            }
            else {
                int old_j = j;
                j = lower_bound(numbers.begin() + i + 1, numbers.begin() + j, target - numbers[i])
                    - numbers.begin();
                if (j == old_j) j--;
            }
        }
        return vector<int>({0, 0});
    }
};
