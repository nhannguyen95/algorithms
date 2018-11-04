// Solution 1: heap
// Using the idea of KMIN
// Time complexity: O(COL) + O(KlogCOL)
// Space complexity: O(COL)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        typedef pair<int, int> ii;
        typedef pair<int, ii> iii;
        priority_queue<iii, vector<iii>, greater<iii>> Q;
        for(int j = 0; j < matrix[0].size(); j++)
            Q.push(make_pair(matrix[0][j], make_pair(0, j)));
        
        while(k --> 1) {  // --> operator lol
            int i = Q.top().second.first;
            int j = Q.top().second.second;
            Q.pop();
            if (i < matrix.size() - 1) {
                i++;
                Q.push(make_pair(matrix[i][j], make_pair(i, j)));
            }
        }
        return Q.top().first;
    }
};
