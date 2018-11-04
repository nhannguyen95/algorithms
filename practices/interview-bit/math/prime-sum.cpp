// O(Asqrt(A)) in time
// O(1) in space
// Can use Sieve instead of isPrime() function
bool isPrime(int x) {
    if (x <= 1) return false;
    for(int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

vector<int> Solution::primesum(int A) {
    assert((A > 2) && (A % 2 == 0));

    vector<int> ans;
    for(int i = 2; i <= A/2; i++) {
        if (isPrime(i) && isPrime(A - i)) {
            ans.push_back(i);
            ans.push_back(A - i);
            break;
        }
    }
    return ans;
}
