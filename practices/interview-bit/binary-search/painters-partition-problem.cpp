// O(1) in space
// O(log(LONG_LONG_MAX) * len(L)) in time
long long sum(const vector<int> &L) {
    long long s = 0;
    for(int x : L) s += x;
    return s;
}

bool check(long long maxTime, const vector<int> & L, const int K) {
    int neededPainter = 0;
    long long timePerPainter = 0;
    for(int l : L) {
        if ((long long)l > maxTime) return false;
        if (timePerPainter + l > maxTime) {
            neededPainter++;
            timePerPainter = l;
        } else {
            timePerPainter += l;
        }
    }

    return neededPainter + 1 <= K;
}

int Solution::paint(int K, int T, vector<int> &L) {
    int mod = 10000003;
    long long low = 0;
    long long high = sum(L);  // Maximum time needed
    while(low < high) {
        long long mid = low + ((high - low) >> 1);
        if (check(mid, L, K)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    return ((high % mod) * T) % mod;
}
