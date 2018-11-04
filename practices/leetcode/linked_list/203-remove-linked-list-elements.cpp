// Solution 1:Linus's technique
// O(1) in space, O(N) in time
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode** pp = &head;
        ListNode* entry = head;
        while(entry) {
            ListNode* afterEntry = entry->next;
            if (entry->val == val) {  // Remove this value
                *pp = entry->next;
                
                // Free memory
                delete entry;
                entry = NULL;
            } else {
                pp = &(entry->next);
            }
            entry = afterEntry;
        }
        return head;
    }
};

// Solution 2: recursive
// O(N) in time and space
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) return head;
        ListNode* nextHead = removeElements(head->next, val);
        if (head->val == val) {
            delete head;
            head = NULL;
            return nextHead;
        }
        head->next = nextHead;
        return head;
    }
};
