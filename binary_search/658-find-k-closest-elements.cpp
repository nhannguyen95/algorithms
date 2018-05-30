// Solution 1: accumulative sum + linear scan
// O(2N) in time, O(N) in space
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<long long> dp(n, 0);
        dp[0] = abs(arr[0] - x);
        for(int i = 1; i < n; i++)
            dp[i] = dp[i-1] + abs(arr[i] - x);
        
        int mn = INT_MAX;
        int bg = 0;  // begin
        for(int i = 0; i < n-k+1; i++) {
            long long temp = dp[i+k-1] - ((i > 0) ? dp[i-1] : 0);
            if (temp < mn) {
                cout << i << ' ' << temp << '\n';
                mn = temp;
                bg = i;
            }
        }
        return vector<int>(arr.begin()+bg, arr.begin()+bg+k);
    }
};

// Solution 2: accumulative sum + binary search
// O(N + log(N-k)) in time, O(N) in space
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<long long> dp(n, 0);
        dp[0] = abs(arr[0] - x);
        for(int i = 1; i < n; i++)
            dp[i] = dp[i-1] + abs(arr[i] - x);
        
        int low = 0;  // [0, n-k]
        int high = n-k;
        while(low < high) {
            int mid = (low + high) / 2;
            long long sumMid = dp[mid+k-1] - (mid > 0 ? dp[mid-1] : 0);
            long long sumRight = dp[mid+k] - dp[mid];
            if (sumMid > sumRight) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return vector<int>(arr.begin()+low, arr.begin()+low+k);
    }
};

// Solution 3: binary search + 2 pointer
// O(logN + k) in time, O(K) in space (for storing result)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = (int)arr.size();
        
        // Base cases
        if (x <= arr[0]) return vector<int>(arr.begin(), arr.begin()+k);
        if (x >= arr[n-1]) return vector<int>(arr.end()-k, arr.end());
        
        // Find min low: arr[low] >= x
        int low = 0;
        int high = n-1;
        while(low < high) {
            int mid = (low + high) / 2;
            if (arr[mid] < x) low = mid + 1;
            else high = mid;
        }
        
        // Shrink possible range
        int id = low;
        low = max(0, id-k-1);
        high = min(n-1, id+k-1);
        while(high - low > k - 1) {
            if (x - arr[low] > arr[high] - x) low++;
            else high--;
        }
        return vector<int>(arr.begin()+low, arr.begin()+high+1);
    }
};
