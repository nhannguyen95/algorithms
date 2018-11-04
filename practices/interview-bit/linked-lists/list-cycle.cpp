/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Solution 1: O(N) space
ListNode* Solution::detectCycle(ListNode* head) {
    unordered_set<ListNode*> set;
    while(head != NULL) {
        if (set.find(head) != set.end()) {
            return head;
        }
        set.insert(head);
        head = head->next;
    }

    return NULL;
}

// Solution 2: O(1) space
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* head) {
    // Base case
    if (head == NULL || head->next == NULL)
        return NULL;

    // Detect cycle
    ListNode * slow = head;
    ListNode * fast = head->next;
    while(slow != fast) {
        if (fast == NULL || fast->next == NULL)
            return NULL;  // No cycle
        slow = slow->next;
        fast = fast->next->next;
    }


    // Find length of cycle
    fast = slow->next;
    int size = 1;
    while(fast != slow) {
        fast = fast->next;
        size++;
    }

    // Find the node where the cycle begins
    slow = fast = head;
    for(int i = 0; i < size; i++)
        fast = fast->next;

    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}
