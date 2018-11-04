/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Solution 1: O(N) in space
void insertLast(ListNode *& head, ListNode *& tail, int v) {
    // Base case
    if (head == NULL) {
        head = new ListNode(v);
        tail = head;
        return;
    }

    tail->next = new ListNode(v);
    tail = tail->next;
}

ListNode* Solution::partition(ListNode* head, int x) {
    ListNode *ltHead = NULL, *ltTail = NULL;
    ListNode *geHead = NULL, *geTail = NULL;

    while(head) {
        int v = head->val;
        if (v < x) {
            insertLast(ltHead, ltTail, v);
        } else {
            insertLast(geHead, geTail, v);
        }

        head = head->next;
    }

    if (ltTail == NULL) return geHead;

    ltTail->next = geHead;
    return ltHead;
}

// Solution 2: O(1) in memory (in place implementation)
void insertLast(ListNode *& head, ListNode *& tail, ListNode *& p) {
    // Base case
    if (head == NULL) {
        head = tail = p;
        return;
    }

    tail->next = p;
    tail = p;
    tail->next = NULL;
}

ListNode* Solution::partition(ListNode* head, int x) {
    ListNode *ltHead = NULL, *ltTail = NULL;
    ListNode *geHead = NULL, *geTail = NULL;

    ListNode * cur;
    while(head) {
        cur = head;
        head = head->next;

        if (cur->val < x) {
            insertLast(ltHead, ltTail, cur);
        } else {
            insertLast(geHead, geTail, cur);
        }
    }

    if (ltTail == NULL) return geHead;

    ltTail->next = geHead;
    return ltHead;
}
