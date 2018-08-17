// Solution 1: O(1) in time and space
class Solution {
public:
    void deleteNode(ListNode* node) {
        // ListNode* nxt = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        // delete nxt;
    }
};
