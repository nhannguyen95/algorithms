// https://leetcode.com/problems/pyramid-transition-matrix/solution/

// Solution 1: Brute force
class Solution {
public:
    set<char> join2Buckets(vector<set<char>>& buckets, int i,
                  map<pair<char, char>, vector<char>> & join) {
        set<char> bucket;
        for(char c : buckets[i])
            for(char d : buckets[i+1]) {
                if (join.find({c, d}) != join.end()) {
                    for(char e : join[{c, d}])
                        bucket.insert(e);
                }
            }
        return bucket;
    }
    
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        map<pair<char, char>, vector<char>> join;
        for(string & triplet: allowed) 
            join[{triplet[0], triplet[1]}].push_back(triplet[2]);
        
        vector<set<char>> preBuckets;
        for(char c : bottom) preBuckets.push_back(set<char>({c}));
        for(int i = 0; i < (int)bottom.size()-1; i++) {
            vector<set<char>> curBuckets;
            for(int j = 0; j < (int)preBuckets.size()-1; j++) {
                auto bucket = join2Buckets(preBuckets, j, join);
                if (bucket.size() == 0) return false;
                curBuckets.push_back(bucket);
            }
            preBuckets = curBuckets;
        }
        return true;
    }
};
