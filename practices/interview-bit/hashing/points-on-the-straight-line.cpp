// Solution 1: hashing coefficients (a,b,c) of a straight line ax+by+c=0
// Partially correct
// N = number of distinct points
// O(N^2) in time
// O(N^2) in space
string key(int a, int b) {
    return to_string(a) + "#" + to_string(b);
}

string key(int a, int b, int c) {
    return key(a, b) + "#" + to_string(c);
}

int gcd(int a, int b) {
    return (a != 0) ? gcd(b % a, a) : b;
}

// Return x such that x(x-1) = p
long long findNumPoints(long long p) {
    long long lo = 2;
    long long hi = 1e9;
    while(lo <= hi) {
        long long x = (lo + hi) / 2;
        long long t = x*(x-1);
        if (t == p) {
            return x;
        }
        else if (t > p) hi = x - 1;
        else lo = x + 1;
    }
    return 0;
}

int Solution::maxPoints(vector<int> &X, vector<int> &Y) {
    int n = (int)X.size();

    // Save duplicated points indices to 'ids'
    unordered_map<string, int> P;
    vector<int> ids;
    for(int i = 0; i < (int)X.size(); i++) {
        if (P.find(key(X[i],Y[i])) == P.end())
            ids.push_back(i);
        P[key(X[i],Y[i])]++;
    }

    // Base cases
    if (ids.size() == 0) return 0;
    if (ids.size() == 1) return P[key(X[ids[0]],Y[ids[0]])];

    unordered_map<string, long long> dis, dup;
    int cnt = 0;
    for(int i : ids) {
        for(int j : ids) {
            if (i == j) continue;

            // Point 'i' and point 'j' are on the line ax + by + c = 0
            int a = Y[i] - Y[j];
            int b = X[j] - X[i];
            int c = -X[i]*(Y[i]-Y[j])-Y[i]*(X[j]-X[i]);

            // Standardize
            int g = gcd(a, gcd(b, c));
            if (g != 0) {
                a /= g;
                b /= g;
                c /= g;
            }
            if (a < 0) { a = -a; b = -b; c = -c; }
            else if (a == 0 && b < 0) { b = -b; c = -c; }
            else if (a == 0 && b == 0 && c < 0) { c = -c; }

            dis[key(a, b, c)] += 2;
            dup[key(a, b, c)] += (P[key(X[i],Y[i])] + P[key(X[j],Y[j])]);
        }
    }

    long long maxPoints = 2;
    for(auto p : dis) {
        long long _dis = findNumPoints(p.second/2);
        long long _dup = dup[p.first] / (2 * (_dis-1));
        maxPoints = max(maxPoints, _dup);
    }
    return (int)maxPoints;
}

// Solution 2: Official Answer
// N = total points
// O(N^2) in time
// O(N) in space
int gcd(int a, int b) {
    return (a != 0) ? gcd(b % a, a) : b;
}

int Solution::maxPoints(vector<int> &X, vector<int> &Y) {
    int ans = 0;
    map<pair<int, int>, int> M;
    for(int i = 0; i < (int)X.size(); i++) {
        M.clear();
        int same = 1, curMax = 0;
        for(int j = i+1; j < (int)X.size(); j++) {
            int xdiff = X[j] - X[i];
            int ydiff = Y[j] - Y[i];
            if (xdiff == 0 && ydiff == 0) {
                // Same point
                same++;
                continue;
            }
            if (xdiff < 0) {
                xdiff *= -1;
                ydiff *= -1;
            }
            int g = gcd(xdiff, ydiff);
            M[make_pair(xdiff / g, ydiff / g)]++;
            curMax = max(curMax, M[make_pair(xdiff / g, ydiff / g)]);
        }
        curMax += same;
        ans = max(ans, curMax);
    }
    return ans;
}
