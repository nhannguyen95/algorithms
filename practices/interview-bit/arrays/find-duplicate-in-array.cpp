// The tortoise and hare algorithm
// O(1) in space
// O(N) in memory
int Solution::repeatedNumber(const vector<int> &A) {
    if (A.size() <= 1) return -1;

    int slow = A[0];
    int fast = A[A[0]];  // Theoretically slow = fast = 0
    while(slow != fast) {
        slow = A[slow];
        fast = A[A[fast]];
    }

    fast = 0;
    while(slow != fast) {
        slow = A[slow];
        fast = A[fast];
    }
    return slow;
}
