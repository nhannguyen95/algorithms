/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Solution 1
ListNode* Solution::deleteDuplicates(ListNode* head) {
    ListNode * slow = head;
    while(slow != NULL) {
        ListNode * fast = slow->next;
        while(fast != NULL && slow->val == fast->val)
            fast = fast->next;
        slow->next = fast;
        slow = fast;
    }
    return head;
}

// Solution 2
ListNode* Solution::deleteDuplicates(ListNode* head) {
    ListNode * origin = head;
    while(head != NULL) {
        while(head->next != NULL && head->val == head->next->val)
            head->next = head->next->next;
        head = head->next;
    }
    return origin;
}
