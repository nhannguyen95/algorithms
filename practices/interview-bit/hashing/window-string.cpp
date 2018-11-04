// Solution 1: Partially correct
bool isValid(unordered_map<char, int> & CNT, unordered_map<char, int> & cnt) {
    for(auto pair : CNT) {
        char c = pair.first;
        if (cnt.find(c) == cnt.end()) return false;
        if (CNT[c] > cnt[c]) return false;
    }
    return true;
}

string Solution::minWindow(string S, string T) {
    unordered_map<char, int> CNT;
    for(char c : T) CNT[c]++;

    unordered_map<char, int> cnt;
    int low = 0;
    string ans = "";
    for(int high = 0; high < (int)S.size(); high++) {
        char c = S[high];
        if (CNT.find(c) == CNT.end()) continue;

        cnt[c]++;
        string t = S.substr(low, high - low + 1);
        reverse(t.begin(), t.end());
        while(low <= high) {
            if (CNT.find(S[low]) != CNT.end()) {
                if (isValid(CNT, cnt)) {
                    if (ans == "" || ans.size() > t.size()) {
                        ans = t;
                    }
                } else {
                    break;
                }
                cnt[S[low]]--;
            }
            low++;
            t.pop_back();
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// Solution 2
// N = len(S), M = len(T)
// O(M) in space
// O(N+M) in time
string Solution::minWindow(string S, string T) {
    unordered_map<char, int> counts;
    for(char c : T) counts[c]++;

    int total = 0, start = 0, length = 0;
    for(int head = 0, tail = 0; tail < (int)S.size(); tail++) {
        if (counts.find(S[tail]) == counts.end()) {
            // Current character doesn't appear in T,
            // no need to care about it
            continue;
        }

        counts[S[tail]]--;
        if (counts[S[tail]] >= 0) {
            total++;  // We've already found 'total' characters in T
        }

        if (total == (int)T.size()) {
            // At this point, counts[c] < 0 means character c (in T) is
            // overused

            // One moment at a time, there is only atmost 1 characters in c
            // such that counts[c] < 0 (can only be equal to -1), using two
            // pointers to `recover` it
            while(counts.find(S[head]) == counts.end() || counts[S[head]] < 0) {
                if (counts.find(S[head]) != counts.end()) counts[S[head]]++;
                head++;
            }

            // Now [head, tail] is a valid substring
            if (length == 0 || tail-head+1 < length) {
                start = head;
                length = tail-head+1;
            }
        }
    }
    return S.substr(start, length);
}
