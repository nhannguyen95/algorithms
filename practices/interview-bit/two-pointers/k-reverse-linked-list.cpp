// Solution 1: O(N) in space
void printList(ListNode * p) {
    while(p) {
        cout << p->val << ' ';
        p = p->next;
    }
}

ListNode* Solution::reverseList(ListNode* head, int k) {
    // Base case
    if (head == NULL || k == 1) {
        // return head;
        printList(head);
        return NULL;
    }

    int cnt = 1;
    ListNode * list = head;
    ListNode *cur = NULL,
             *preTail = NULL,
             *curHead = NULL,
             *curTail = NULL;
    bool firstReverse = true;
    while(list != NULL) {
        cur = list;
        list = list->next;

        if (cnt == 1) {
            preTail = curTail;

            curHead = new ListNode(cur->val);
            curTail = curHead;
        } else if (cnt <= k) {
            ListNode * p = new ListNode(cur->val);
            p->next = curHead;
            curHead = p;

            if (cnt == k) {
                // curTail->next = list;
                cnt = 0;
                if (preTail != NULL) preTail->next = curHead;

                if (firstReverse) {
                    head = curHead;
                    firstReverse = false;
                }
            }
        }
        cnt++;
    }

    // return head;
    printList(head);
    return NULL;
}

// Solution 2: O(N) solution
void printList(ListNode * p) {
    while(p) {
        cout << p->val << ' ';
        p = p->next;
    }
}

ListNode* Solution::reverseList(ListNode* head, int k) {
    // Base case
    if (head == NULL || k == 1) {
        // return head;
        printList(head);
        return NULL;
    }

    int cnt = 1;
    ListNode * list = head;
    ListNode *cur = NULL,
             *preTail = NULL,
             *curHead = NULL,
             *curTail = NULL;
    bool firstReverse = true;
    while(list != NULL) {
        cur = list;
        list = list->next;

        if (cnt == 1) {
            preTail = curTail;

            curHead = cur;
            curTail = curHead;
        } else if (cnt <= k) {
            cur->next = curHead;
            curHead = cur;

            if (cnt == k) {
                // curTail->next = list;
                cnt = 0;
                if (preTail) preTail->next = curHead;

                if (firstReverse) {
                    head = curHead;
                    firstReverse = false;
                }
            }
        }
        cnt++;
    }
    curTail->next = NULL;

    // return head;
    printList(head);
    return NULL;
}
