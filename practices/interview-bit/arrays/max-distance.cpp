// O(NlogN) in time
// O(N) in space
int Solution::maximumGap(const vector<int> &A) {
    // Base case
    if ((int) A.size() == 0) return -1;

    vector<pair<int, int>> numbers;
    for(int i = 0; i < (int) A.size(); i++) {
        numbers.push_back(make_pair(A[i], i));
    }
    sort(numbers.begin(), numbers.end());

    int maxLeft = numbers.back().second;
    int maxDist = 0;
    for(int i = (int) numbers.size() - 2; i >= 0; i--) {
        maxDist = max(maxDist, maxLeft - numbers[i].second);
        maxLeft = max(maxLeft, numbers[i].second);
    }
    return maxDist;
}
