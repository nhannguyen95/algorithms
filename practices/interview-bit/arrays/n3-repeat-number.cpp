// O(1) in space
// O(size(A)) in time
int countNumber(const vector<int> & A, const int & x) {
    int count = 0;
    for(int num : A) {
        if (x == num) count++;
    }
    return count;
}

int Solution::repeatedNumber(const vector<int> &A) {
    assert(A.size() > 0);
    if (A.size() <= 2) return A[0];

    int num0(0), num1(0);
    int count0(0), count1(0);
    for(int i = 0; i < (int) A.size(); i++) {
        if (count0 == 0 && count1 == 0) {
            count0++;
            num0 = A[i];
        } else if (count0 == 0) {
            if (A[i] == num1) count1++;
            else {
                count0++;
                num0 = A[i];
            }
        } else if (count1 == 0) {
            if (A[i] == num0) count0++;
            else {
                count1++;
                num1 = A[i];
            }
        } else if (A[i] == num0) {
            count0++;
        } else if (A[i] == num1) {
            count1++;
        } else {
            count0--;
            count1--;
        }
    }

    if (countNumber(A, num0) > A.size() / 3) return num0;
    if (countNumber(A, num1) > A.size() / 3) return num1;
    return -1;
}
