// Use data structure to avoid duplicate (set)
vector<vector<int> > Solution::threeSum(vector<int> &S) {
    sort(S.begin(), S.end());
    vector<vector<int>> triplets;
    set<pair<int, int>> doublets;
    for(int i = 0; i < (int)S.size() - 2; i++) {
        // Find S[j] + S[k] = -S[i]
        int j = i + 1;
        int k = (int)S.size() - 1;
        while(j < k) {
            int sum = S[j] + S[k];
            if (sum == -S[i]) {
                pair<int, int> doublet(S[i], S[j]);
                if (doublets.find(doublet) == doublets.end()) {
                    doublets.insert(doublet);
                    triplets.push_back(vector<int>({S[i], S[j], S[k]}));
                }
            }

            if (sum > -S[i]) k--;
            else j++;
        }
    }

    return triplets;
}

// Avoid duplicate without data structure
vector<vector<int> > Solution::threeSum(vector<int> &S) {
    sort(S.begin(), S.end());
    vector<vector<int>> ans;
    for(int i = 0; i < (int)S.size() - 2; i++) {
        if (i > 0 && S[i] == S[i - 1]) continue;

        // Find S[j] + S[k] = -S[i]
        int j = i + 1;
        int k = (int)S.size() - 1;
        while(j < k) {
            int sum = S[i] + S[j] + S[k];
            if (sum == 0) ans.push_back(vector<int>({S[i], S[j], S[k]}));

            if (sum > 0) k--;
            else if (sum < 0) j++;
            else {
                j++;
                while(j < k && S[j] == S[j - 1]) j++;
            }
        }
    }

    return ans;
}
