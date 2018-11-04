/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Solution 1: Find out the length of the list in one go.
// Then you know the number of node to be removed. Traverse to the node and remove it
int getSize(ListNode * head) {
    int size = 0;
    while(head != NULL) {
        size++;
        head = head->next;
    }
    return size;
}

ListNode* Solution::removeNthFromEnd(ListNode* head, int n) {
    int size = getSize(head);
    n = size - n;  // Now delete the n-th element from the head
                   // (0 based-index)

    if (n >= size) return head;

    if (n <= 0) return head->next;

    ListNode * p = head;
    int cnt = 0;
    while(p != NULL) {
        if (cnt == n - 1) {
            p->next = p->next->next;
            break;
        }
        p = p->next;
        cnt++;
    }

    return head;
}

// Solution 2: Make the first pointer go n nodes. Then move the second and first
// pointer simultaneously. This way, the first pointer is always ahead of the second
// pointer by n nodes. So when first pointer reaches the end, you are on the node to be removed.
ListNode* Solution::removeNthFromEnd(ListNode* head, int n) {
    ListNode **p1 = &head, *p2 = head;
    for(int i = 1; i < n; i++) {
        if (p2->next == NULL) return head->next;
        p2 = p2->next;
    }

    while(p2->next != NULL) {
        p1 = &((*p1)->next);
        p2 = p2->next;
    }

    (*p1) = (*p1)->next;
    return head;
}
