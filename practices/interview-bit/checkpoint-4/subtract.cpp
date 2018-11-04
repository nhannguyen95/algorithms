// O(1) in space
// O(N) in memory
int getSize(ListNode * head) {
    int size = 0;
    while(head) {
        size++;
        head = head->next;
    }
    return size;
}

// Reverse the linked list `head`
// Return: reversed-list's head
ListNode * reverse(ListNode * head) {
    ListNode * pre = NULL;
    ListNode * cur = NULL;
    while(head) {
        cur = head;
        head = head->next;

        cur->next = pre;
        pre = cur;
    }
    return cur;
}

ListNode* Solution::subtract(ListNode* head) {
    int size = getSize(head);

    // Split the linked list at middle into 2 halve
    ListNode * tail = head;
    for(int i = 1; i < size/2; i++) {
        tail = tail->next;
    }
    ListNode * head2 = tail->next;
    tail->next = NULL;

    // Reverse the second half
    head2 = reverse(head2);

    // Modify the node in the first half
    ListNode * p = head;
    ListNode * p2 = head2;
    while(p != NULL && p2 != NULL) {
        p->val = p2->val - p->val;
        p = p->next;
        p2 = p2->next;
    }

    // Reconnect 2 halve into one linked list
    tail->next = reverse(head2);

    return head;

}
