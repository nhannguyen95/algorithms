// O(sqrt(A)) in time
vector<int> Solution::allFactors(int A) {
    vector<int> factors;
    for(int i = 1; i * i <= A; i++) {
        if (A % i == 0) {
            factors.push_back(i);
            if (i != A / i) {
                factors.push_back(A / i);
            }
        }
    }
    sort(factors.begin(), factors.end());
    return factors;
}
