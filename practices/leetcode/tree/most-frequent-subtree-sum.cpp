// Solution 1: hash table
class Solution {
public:
    int computeSumFrequency(TreeNode* node, unordered_map<int, int> & freq) {
        if (node == NULL) return 0;
        
        int sumLeft = computeSumFrequency(node->left, freq);
        int sumRight = computeSumFrequency(node->right, freq);
        
        int sum = sumLeft + sumRight + node->val;
        freq[sum]++;
        return sum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> sumFreq;
        computeSumFrequency(root, sumFreq);
        
        vector<int> maxFreqSums;
        int maxFreq = 0;
        for(unsigned i = 0; i < sumFreq.bucket_count(); i++) {
            for(auto it = sumFreq.begin(i); it != sumFreq.end(i); it++) {
                int sum = it->first;
                int freq = it->second;
                if (freq > maxFreq) {
                    maxFreqSums.clear();
                    maxFreq = freq;
                }
                if (freq == maxFreq)
                    maxFreqSums.push_back(sum);
            }
        }
        return maxFreqSums;
    }
};
