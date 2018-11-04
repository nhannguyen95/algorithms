// Solution 1:
void insert(ListNode *& head, ListNode *& node) {
    // Base case: `node` is insterted at the beginning
    if (head->val >= node->val) {
        node->next = head;
        head = node;
        return;
    }

    // `q` is the right most node whose value < `node`->val
    ListNode * p = head, * q = head;
    while(p->val < node->val) {
        q = p;
        p = p->next;
    }

    node->next = p;
    q->next = node;
}

ListNode* Solution::insertionSortList(ListNode* head) {
    // Base case
    if (head == NULL || head->next == NULL)
        return head;

    ListNode * cur = head;
    while(cur != NULL && cur->next != NULL) {
        ListNode * nxt = cur->next;  // Try to insert "nxt" pointer

        if (cur->val > nxt->val) {  // Need to insert
            cur->next = nxt->next;
            insert(head, nxt);
        } else {
            cur = cur->next;
        }
    }
    return head;
}

// Solution 2:

ListNode * Solution::insertionSortList(ListNode * head) {
   // Base case
   if (head == NULL || head->next == NULL)
       return head;

   ListNode * sorted = NULL;
   ListNode * list = head;
   while(list) {
       ListNode * cur = list;
       list = list->next;
       if (sorted == NULL || sorted->val >= cur->val) {
           cur->next = sorted;
           sorted = cur;
       } else {
           ListNode * tmp = sorted;

           while(tmp) {
               ListNode * p = tmp;
               tmp = tmp->next;

               if (p->next == NULL || p->next->val >= cur->val) {
                   cur->next = p->next;
                   p->next = cur;
                   break;
               }
           }
       }
   }
   return sorted;
}
