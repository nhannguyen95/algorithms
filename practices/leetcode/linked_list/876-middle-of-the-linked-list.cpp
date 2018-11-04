// Solution 1: iterative, won't work with cycled linked-list
// O(1) in space, O(N + N/2) in time
class Solution {
public:
    int getListLength(ListNode* head) {
        int len = 0;
        while(head != NULL) {
            len++;
            head = head->next;
        }
        return len;
    }
    
    ListNode* middleNode(ListNode* head) {
        int len = getListLength(head);   
        for(int i = 0; i < len / 2; i++)
            head = head->next;
        return head;
    }
};

// Solution 2: Recursive, won't work with cycled linked-list
// O(N/2) in space, O(N + N/2) in space
class Solution {
public:
    int getListLength(ListNode* head) {
        int len = 0;
        while(head != NULL) {
            len++;
            head = head->next;
        }
        return len;
    }
    
    ListNode* middleNodeHelper(ListNode* head, int len) {
        if (len == 0 || len == 1) return head;
        return middleNodeHelper(head->next, len - 2);
    }
    
    ListNode* middleNode(ListNode* head) {
        int len = getListLength(head);   
        return middleNodeHelper(head, len);
    }
};

// Solution 3: Slow and Fast pointers (the most optimal method)
// Can be modified to work with cycled linked-list
// O(1) in space, O(N/2) in time
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
