// Naive solution
int Solution::solve(string A) {

    string reversedA(A);
    reverse(reversedA.begin(), reversedA.end());

    // A:        (bab)b
    // revA:    b(bab)
    // => need to insert 1 character (b)
    int len = (int)A.size();
    for(int i = len; i >= 1; i--) {
        if (A.compare(0, i, reversedA.substr(len - i)) == 0) {
            return len - i;
        }
    }

}

// KMP Application
int Solution::solve(string A) {

    string reversedA(A);
    reverse(reversedA.begin(), reversedA.end());

    int i = 0, j = -1;
    vector<int> b(A.size() + 1, - 1);
    while(i < A.size()) {
        while(j >= 0 && A[i] != A[j]) j = b[j];
        i++; j++;
        b[i] = j;
    }

    i = 0, j = 0;
    while(i < reversedA.size()) {
        while(j >= 0 && reversedA[i] != A[j]) j = b[j];
        i++; j++;
    }

    return A.size() - j;
}
