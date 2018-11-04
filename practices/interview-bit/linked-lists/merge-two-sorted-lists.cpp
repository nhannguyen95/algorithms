/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Solution 1: O(N) in space
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    // Base case
    if (A == NULL && B == NULL) return NULL;

    ListNode * be4head = new ListNode(0);
    ListNode * head = be4head;
    while(A != NULL && B != NULL) {
        int mn = min(A->val, B->val);
        head->next = new ListNode(mn);
        head = head->next;

        if (mn == A->val) A = A->next;
        else B = B->next;
    }

    while(A != NULL) {
        head->next = new ListNode(A->val);
        head = head->next;
        A = A->next;
    }

    while(B != NULL) {
        head->next = new ListNode(B->val);
        head = head->next;
        B = B->next;
    }

    ListNode * t = be4head;
    be4head = be4head->next;
    delete t;
    return be4head;
}

// Solution 2: O(1) in space
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    if (A == NULL) return B;
    if (B == NULL) return A;

    ListNode * head = NULL;
    if (A->val < B->val) {
        head = A;
        A = A->next;
    } else {
        head = B;
        B = B->next;
    }

    ListNode * p = head;

    while(A != NULL && B != NULL) {
        if (A->val < B->val) {
            p->next = A;
            A = A->next;
        } else {
            p->next = B;
            B = B->next;
        }
        p = p->next;
    }

    if (A != NULL) {
        p->next = A;
    } else {
        p->next = B;
    }

    return head;
}
