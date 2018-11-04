// O(AlogA) in time
// O(A) in space
vector<int> Solution::sieve(int A) {
    // Base cases
    if (A <= 1) return vector<int>();

    vector<bool> isPrime(A + 1, true);
    vector<int> primes;
    isPrime[1] = false;
    isPrime[2] = true;
    for(int i = 2; i <= A; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for(int j = i * i; j <= A; j += i) {
                isPrime[j] = false;
            }
        }
    }

    return primes;
}
