// Solution 1: DFS
// N = number of nodes
// O(N) in time
// O(maximum number of levels) in space
// pattern: preorder
class Solution {
public:
    void averageOfLevels(TreeNode* node, int level, vector<double>& avg, vector<int>& cnt) {
        if (node == NULL) return;

        if (level >= (int)avg.size()) {
            avg.push_back((double)node->val);
            cnt.push_back(1);
        } else {
            avg[level] += node->val;
            cnt[level]++;
        }

        averageOfLevels(node->left, level + 1, avg, cnt);
        averageOfLevels(node->right, level + 1, avg, cnt);
    }

    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> avg;
        vector<int> cnt;
        averageOfLevels(root, 0, avg, cnt);
        for(int i = 0; i < (int)avg.size(); i++) {
            avg[i] /= cnt[i];
        }
        return avg;
    }
};

// Solution 2: BFS (iterative)
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        // Base case
        if (root == NULL) return vector<double>();

        stack<TreeNode*> currLevel;
        currLevel.push(root);

        vector<double> avg;
        while(!currLevel.empty()) {
            long long sum = 0;
            int cnt = 0;
            stack<TreeNode*> nextLevel;
            while(!currLevel.empty()) {
                TreeNode * node = currLevel.top();
                currLevel.pop();

                sum += node->val;
                cnt++;

                if (node->left != NULL)
                    nextLevel.push(node->left);
                if (node->right != NULL)
                    nextLevel.push(node->right);
            }

            avg.push_back(sum * 1.0 / cnt);
            currLevel = nextLevel;
        }

        return avg;
    }
};
