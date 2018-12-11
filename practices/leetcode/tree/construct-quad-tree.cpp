// https://leetcode.com/problems/construct-quad-tree/

// Solution 1: 
// - Prefix sum: O(N^2)
// - Tree: T(N) = 4T(N/2) + 1 = O(logN)
// => O(N^2)
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    vector<vector<int>> prefixSum2D(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        
        vector<vector<int>> sum(R, vector<int>(C, 0));
        for(int i = 0; i < R; i++) {
            int rowSum = 0;
            for(int j = 0; j < C; j++) {
                rowSum += grid[i][j];
                sum[i][j] = rowSum + ((i == 0) ? 0 : sum[i-1][j]);
            }
        }
        
        return sum;
    }
    
    bool isLeaf(vector<vector<int>>& grid,
                int r1, int c1, int r2, int c2,
                vector<vector<int>>& dp) {
        int sum = dp[r2][c2] -
                  ((r1 > 0) ? dp[r1-1][c2] : 0) -
                  ((c1 > 0) ? dp[r2][c1-1] : 0) +
                  ((r1 > 0 && c1 > 0) ? dp[r1-1][c1-1] : 0);
        int size = r2 - r1 + 1;
        return sum == size * size * grid[r1][c1];
    }
    
    Node* construct(vector<vector<int>>& grid,
                    int r1, int c1, int r2, int c2,
                    vector<vector<int>>& dp) {
        assert((r2 - r1) == (c2 - c1));
        
        Node* root = new Node(false, false, NULL, NULL, NULL, NULL);

        if (isLeaf(grid, r1, c1, r2, c2, dp)) {
            root->isLeaf = true;
            root->val = grid[r1][c1];
            return root;
        }
        
        int rm = (r1 + r2) / 2;
        int cm = (c1 + c2) / 2;  // 3
        
        root->topLeft = construct(grid, r1, c1, rm, cm, dp);
        root->topRight = construct(grid, r1, cm+1, rm, c2, dp);
        root->bottomLeft = construct(grid, rm+1, c1, r2, cm, dp);
        root->bottomRight = construct(grid, rm+1, cm+1, r2, c2, dp);
        
        return root;
    }
    
    Node* construct(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        
        auto dp = prefixSum2D(grid);
        return construct(grid, 0, 0, R-1, C-1, dp);
    }
};

// Solution 2:
// Time complexity:
// T(N) = 4T(N/2) + 1 = (4^logN)T(N/2^logN) + 4^0 + 4^1 + .. 4^(logN-1)
//                    = 4^0 + .. + 4^logN
//                    = [4^(logN+1) - 1] / (4-1)
//                    = [4N^2 - 1] / 3
//                    = O(N^2)
class Solution {
public:
    Node* construct(vector<vector<int>>& grid, int r, int c, int size) {
        if (size == 1)
            return new Node(grid[r][c], true, NULL, NULL, NULL, NULL);
        
        int subsize = size >> 1;
        Node* tl = construct(grid, r, c, subsize);
        Node* tr = construct(grid, r, c+subsize, subsize);
        Node* bl = construct(grid, r+subsize, c, subsize);
        Node* br = construct(grid, r+subsize, c+subsize, subsize);
        
        bool isLeaf = (tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf) &&
                      (tl->val == tr->val) && 
                      (tr->val == bl->val) &&
                      (bl->val == br->val);
        
        if (isLeaf)
            return new Node(tl->val, true, NULL, NULL, NULL, NULL);
        return new Node(false, false, tl, tr, bl, br);
    }
    
    Node* construct(vector<vector<int>>& grid) {
        return construct(grid, 0, 0, grid.size()); 
    }
};
