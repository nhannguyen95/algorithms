long long sum(const vector<int> & A) {
    long long ans = 0;
    for(int x : A) ans += x;
    return ans;
}

int check(long long maxPagePerStudent, const vector<int> & pages, const int & noStudents) {
    int neededStudents = 1;
    long long pagePerStudent = 0;
    for(int p : pages) {
        // p always <= maxPagePerStudent
        if (pagePerStudent + p > maxPagePerStudent) {
            pagePerStudent = p;
            neededStudents++;
        } else {
            pagePerStudent += p;
        }
    }
    return neededStudents - noStudents;
}

int Solution::books(vector<int> &A, int noStudents) {
    int noBooks = (int)A.size();
    if (noBooks < noStudents) return -1;

    long long low = *max_element(A.begin(), A.end());
    long long high = sum(A);  // Total pages
    long long ans = -1;
    while(low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid, A, noStudents) <= 0) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
