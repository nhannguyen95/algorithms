// O(NlogN) in time
// O(logN) in space
int getSize(ListNode * p) {
    int size = 0;
    while(p) {
        size++;
        p = p->next;
    }
    return size;
}

// Merge 2 sorted lists
ListNode * mergeList(ListNode * l1, ListNode * l2) {
    if (!l2) return l1;
    if (!l1) return l2;

    ListNode * head = l1;
    if (l1->val < l2->val) {
        l1 = l1->next;
    } else {
        head = l2;
        l2 = l2->next;
    }
    ListNode * tail = head;

    while(l1 || l2) {
        if (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
        } else if (!l2) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = NULL;

    return head;
}

ListNode * mergeSort(ListNode * head, int l, int r) {
    if (l >= r) return head;

    int mid = (l + r) / 2;
    ListNode * head2 = head;
    for(int i = 0; i < mid - l; i++)
        head2 = head2->next;
    ListNode * p = head2;
    head2 = head2->next;
    p->next = NULL;

    ListNode * list1 = mergeSort(head, l, mid);
    ListNode * list2 = mergeSort(head2, mid + 1, r);

    return mergeList(list1, list2);
}

ListNode* Solution::sortList(ListNode* head) {
    int size = getSize(head);
    return mergeSort(head, 0, size - 1);
}
