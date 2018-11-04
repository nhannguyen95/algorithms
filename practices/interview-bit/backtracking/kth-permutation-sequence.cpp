long long fac(int n) {
    long long res = 1;
    for(int i = 2; i <= n; i++)
        res *= i;
    return res;
}

string Solution::getPermutation(int n, int k) {
    vector<int> nums;
    for(int i = 1; i <= n; i++)
        nums.push_back(i);

    string ans = "";
    for(int i = 1; i <= n; i++) {
        long long rank = 0;
        int size = (int)nums.size();

        // Avoid overflow
        if (size - 1 >= 21) {
            ans += to_string(nums[0]);
            nums.erase(nums.begin());
            continue;
        }

        long long t = fac(size - 1);
        for(int j = 0; j < size; j++) {
            if (rank + t >= k) {
                ans += to_string(nums[j]);
                nums.erase(nums.begin() + j);
                k = k - rank;
                break;
            }
            rank += t;
        }
    }
    return ans;
}
