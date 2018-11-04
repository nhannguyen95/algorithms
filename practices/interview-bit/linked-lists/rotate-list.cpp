/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Solution 1
int getSize(ListNode * head) {
    int size = 0;
    while(head != NULL) {
        head = head->next;
        size++;
    }
    return size;
}

ListNode* Solution::rotateRight(ListNode* head, int k) {
    int n = getSize(head);
    k = k % n;

    if (k == 0 || n <= 1) return head;

    ListNode * slow = head;
    ListNode * fast = head;
    for(int i = 1; i <= k; i++) {
        fast = fast->next;
    }

    while(fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    fast->next = head;
    head = slow->next;
    slow->next = NULL;
    return head;
}

// Solution 2
ListNode* Solution::rotateRight(ListNode* head, int k) {
    int n = 1;
    ListNode * fast = head;
    while(fast->next != NULL) {
        n++;
        fast = fast->next;
    }

    k = k % n;

    // Base case
    if (k == 0 || n <= 1) return head;

    int pos = n - k - 1;
    ListNode * slow = head;
    for(int i = 0; i < pos; i++)
        slow = slow->next;

    fast->next = head;
    head = slow->next;
    slow->next = NULL;
    return head;
}
