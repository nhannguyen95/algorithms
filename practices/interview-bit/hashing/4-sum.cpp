// Solution 1: Hash table
// N = number of elements, M = number of satisfied quadruplets
// O(NlogN + N^3 + MlogM + M) in time
// O(N + M) in space
vector<vector<int> > Solution::fourSum(vector<int> &S, int target) {
    sort(S.begin(), S.end());
    unordered_set<int> pres;
    vector<vector<int>> ans;
    for(int i = 0; i < (int)S.size()-2; i++) {
        for(int j = i+1; j < (int)S.size()-1; j++) {
            for(int k = j+1; k < (int)S.size(); k++) {
                int pre = target-S[i]-S[j]-S[k];
                if (pres.find(pre) != pres.end()) {
                    ans.push_back(vector<int>({pre,S[i],S[j],S[k]}));
                }
            }
        }
        pres.insert(S[i]);
    }
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    return ans;
}

// Solution 2: 2 pointers
// O(N^3 + MlogM + M) in time
// O(M) in space
vector<vector<int> > Solution::fourSum(vector<int> &S, int target) {
    sort(S.begin(), S.end());
    unordered_set<int> pres;
    vector<vector<int>> ans;
    for(int i = 0; i < (int)S.size()-3; i++) {
        for(int j = i+1; j < (int)S.size()-2; j++) {
            // Two pointer: S[k] + S[l] = target - S[i] - S[j];
            int k = j+1;
            int l = (int)S.size()-1;
            while(k < l) {
                int sum = S[i] + S[j] + S[k] + S[l];
                if (sum == target) {
                    ans.push_back(vector<int>({S[i],S[j],S[k],S[l]}));
                    k++;
                    l--;
                } else if (sum < target) {
                    k++;
                } else {
                    l--;
                }
            }
        }
        pres.insert(S[i]);
    }
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    return ans;
}

// Solution 3: improvement of Solution 2
// No need to sort and remove duplicates in 'ans'
// O(N^3 + MlogM + M) in time
// O(M) in space
vector<vector<int> > Solution::fourSum(vector<int> &S, int target) {
    sort(S.begin(), S.end());
    unordered_set<int> pres;
    vector<vector<int>> ans;
    for(int i = 0; i < (int)S.size()-3; i++) {
        if (i > 0 && S[i] == S[i-1]) continue;

        for(int j = i+1; j < (int)S.size()-2; j++) {
            if (j > i+1 && S[j] == S[j-1]) continue;

            // Two pointer: S[k] + S[l] = target - S[i] - S[j];
            int k = j+1;
            int l = (int)S.size()-1;
            while(k < l) {
                int sum = S[i] + S[j] + S[k] + S[l];
                if (sum == target) {
                    ans.push_back(vector<int>({S[i],S[j],S[k],S[l]}));
                    k++;
                    l--;
                    while(k < l && S[k] == S[k-1]) k++;
                } else if (sum < target) {
                    k++;
                } else {
                    l--;
                }
            }
        }
        pres.insert(S[i]);
    }
    // sort(ans.begin(), ans.end());
    // ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    return ans;
}
