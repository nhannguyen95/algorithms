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

// Solution 2: iterative post order
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> sumFreq;
        unordered_map<TreeNode*, int> sumAtNode;
        sumAtNode[(TreeNode*)NULL] = 0;
        TreeNode* node = root;
        TreeNode* lastVisit = NULL;
        stack<TreeNode*> s;
        while(!s.empty() || node != NULL) {
            if (node != NULL) {
                s.push(node);
                node = node->left;
            } else {
                TreeNode* peak = s.top();
                if (peak->right == NULL || peak->right == lastVisit) {
                    sumAtNode[peak] = peak->val
                                    + sumAtNode[peak->left]
                                    + sumAtNode[peak->right];
                    sumFreq[sumAtNode[peak]]++;
                    
                    lastVisit = peak;
                    s.pop();
                } else {
                    node = peak->right;
                }
            }
        }
        
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
