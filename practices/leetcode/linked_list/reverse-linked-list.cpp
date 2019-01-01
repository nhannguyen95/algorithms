// https://leetcode.com/problems/reverse-linked-list/

// Solution 1: iterative
// O(1) in space, O(N) in time
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* head2 = NULL;
        while(head != NULL) {
            ListNode* next = head->next;
            head->next = head2;
            head2 = head;
            head = next;
        }
        return head2;
    }
};

// Solution 2: recursive
// O(N) in space, O(N) in time
class Solution {
public:
    pair<ListNode*, ListNode*> reverseListHelper(ListNode* node) {
        if (node == NULL || node->next == NULL)
            return make_pair(node, node);
        
        pair<ListNode*, ListNode*> p = reverseListHelper(node->next);
        ListNode* head = p.first;
        ListNode* tail = p.second;
        
        tail->next = node;
        node->next = NULL;
        
        return make_pair(head, node);
    }
    
    ListNode* reverseList(ListNode* head) {
        return reverseListHelper(head).first;
    }
};

// Solution 3: a more subtle recursive
// O(N) in time and space
class Solution {
public:
    ListNode* reverseList(ListNode* node) {
        if (node == NULL || node->next == NULL)
            return node;
        ListNode* head = reverseList(node->next);
        node->next->next = node;
        node->next = NULL;
        return head;
    }
};
