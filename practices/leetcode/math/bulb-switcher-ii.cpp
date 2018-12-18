// https://leetcode.com/problems/bulb-switcher-ii/

class Solution {
public:
    enum OPS {
        FLIP_ALL,
        FLIP_EVEN,
        FLIP_ODD,
        FLIP_3K1
    }; 
    
    // int binToDec(vector<int>& bin) {
    //     int dec = 0;
    //     for(int b : bin)
    //         dec = 2*dec + b;
    //     return dec;
    // }
    
    vector<int> flip(OPS op, const vector<int>& status) {
        vector<int> res = status;
        int n = res.size();
        switch(op) {
            case FLIP_ALL:
                for(int i = 0; i < n; i++)
                    res[i] = 1 - res[i];
                break;
            case FLIP_EVEN:
                for(int i = 0; i < n; i += 2)
                    res[i] = 1 - res[i];
                break;
            case FLIP_ODD:
                for(int i = 1; i < n; i += 2)
                    res[i] = 1 - res[i];
                break;
            case FLIP_3K1:
                for(int k = 0; 3*k < n; k++)
                    res[3*k] = 1 - res[3*k];
        }
        return res;
    }
    
    // void count(vector<int> status, int m, set<int>& seen) {
    //     int s = binToDec(status);
    //     if (seen.find(s) != seen.end()) return;
    //     seen.insert(s);
    //     if (m == 0) return;
    //     count(flip(OPS::FLIP_ALL, status), m-1, seen);
    //     count(flip(OPS::FLIP_EVEN, status), m-1, seen);
    //     count(flip(OPS::FLIP_ODD, status), m-1, seen);
    //     count(flip(OPS::FLIP_3K1, status), m-1, seen);
    // }
    

    int flipLights(int n, int m) {
        if (n == 0) return 0;
        if (m == 0) return 1;
        
        n = min(n, 4);
        set<vector<int>> s;
        set<vector<int>> finalOp;
        for(int i = 1; i <= m; i++) {
            set<vector<int>> *temp = &s;
            if (i == m) temp = &finalOp;
            
            if (s.size() == 0) {
                vector<int> status(n, 1);
                
                temp->insert(flip(OPS::FLIP_ALL, status));
                temp->insert(flip(OPS::FLIP_EVEN, status));
                temp->insert(flip(OPS::FLIP_ODD, status));
                temp->insert(flip(OPS::FLIP_3K1, status));
            } else {
                
                for(const vector<int> & status : s) {
                    temp->insert(flip(OPS::FLIP_ALL, status));
                    temp->insert(flip(OPS::FLIP_EVEN, status));
                    temp->insert(flip(OPS::FLIP_ODD, status));
                    temp->insert(flip(OPS::FLIP_3K1, status));
                }
            }
        }
        return finalOp.size();

// 1 1 1 1  --> 1 0 1 1
// 0 0 0 0  --> 0 1 0 0
// 0 1 0 1  --> 0 0 0 1
// 1 0 1 0  --> 1 1 1 0

// 1 0 1 1
    }
};
