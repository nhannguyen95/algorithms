// Solution 1: using stack O(N) in space
int getSize(ListNode * head) {
    int size = 0;
    while(head != NULL) {
        head = head->next;
        size++;
    }
    return size;
}

int Solution::lPalin(ListNode* head) {
    int size = getSize(head);

    if (size <= 1) return 1;

    stack<int> st;
    int cnt = 0;
    while(head != NULL) {

        if (size % 2 == 0 || cnt != size/2) {
            if (!st.empty() && st.top() == head->val) {
                st.pop();
            } else {
                st.push(head->val);
            }
        }

        head = head->next;
        cnt++;
    }

    return st.empty() == true;
}

// Solution 2: O(1) in space
// Check if first half == reverse(last half)
int getSize(ListNode * head) {
    int size = 0;
    while(head != NULL) {
        head = head->next;
        size++;
    }
    return size;
}

// Reverse the link list with head `head`
// Return the head of the reversed list
ListNode * reverseList(ListNode * head) {
    if (head == NULL || head->next == NULL)
        return head;

    ListNode * pre = NULL;
    while(head != NULL) {
        ListNode * cur = head;
        head = head->next;

        cur->next = pre;
        pre = cur;
    }

    return pre;
}

int Solution::lPalin(ListNode* head) {
    int size = getSize(head);

    if (size <= 1) return 1;

    ListNode * head2 = head;  // The head of the last half
    int cnt = 0;
    while(cnt < size/2) {
        head2 = head2->next;
        cnt++;
    }
    if (size % 2 == 1) head2 = head2->next;

    // Reverse the last half
    head2 = reverseList(head2);

    // Compare first half and reverse(last half)
    while(head2 != NULL) {
        if (head->val != head2->val)
            return 0;
        head = head->next;
        head2 = head2->next;
    }
    return 1;
}
