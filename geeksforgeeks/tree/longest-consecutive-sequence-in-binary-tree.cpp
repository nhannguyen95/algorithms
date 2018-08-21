// Longest consecutive sequence in Binary tree
// https://www.geeksforgeeks.org/longest-consecutive-sequence-binary-tree/

// Solution 1: recursive
// O(N) in time, O(logN) in space in avg
bool isConsecutive(int a, int b, int c) {
    return (b - a == 1 && c - b == 1) ||
           (a - b == 1 && b - c == 1);
}

int maxConsecutiveLengthFromNode(Node* node, int & res) {
    if (node == NULL) return 0;
    
    int leftLen = maxConsecutiveLengthFromNode(node->left, res);
    int rightLen = maxConsecutiveLengthFromNode(node->right, res);
    
    // Include the current node
    if (node->left == NULL || abs(node->data - node->left->data) == 1)
        leftLen++;
    else
        leftLen = 1;
    if (node->right == NULL || abs(node->data - node->right->data) == 1)
        rightLen++;
    else
        rightLen = 1;
        
    // Update res
    int joinLen = 1;
    if (node->left != NULL && node->right != NULL &&
        isConsecutive(node->left->data, node->data, node->right->data)) {
        joinLen = leftLen + rightLen - 1;
    } else {
        joinLen = max(leftLen, rightLen);
    }
    res = max(res, joinLen);
        
    return max(leftLen, rightLen);
}

int longestConsecutive(Node* root) {
    int res = 1;
    maxConsecutiveLengthFromNode(root, res);
    return (res == 1) ? -1 : res;
}
