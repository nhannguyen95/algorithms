// Solution 1 (long version) - need to add leading zeros
// O(N) in space
int getSize(ListNode * head) {
    int size = 0;
    while(head) {
        head = head->next;
        size++;
    }
    return size;
}

void insertLast(ListNode *& head, ListNode *& tail, int v) {
    if (head == NULL) {
        head = new ListNode(v);
        tail = head;
        return;
    }

    tail->next = new ListNode(v);
    tail = tail->next;
}

ListNode * getTail(ListNode * head) {
    if (head == NULL) return NULL;

    ListNode * tail = head;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    return tail;
}

void addUpZeros(ListNode *& A, ListNode *& B) {
    int sizeA = getSize(A);
    int sizeB = getSize(B);

    ListNode * tailA = getTail(A);
    ListNode * tailB = getTail(B);

    while(sizeA != sizeB) {
        if (sizeA < sizeB) {
            insertLast(A, tailA, 0);
            sizeA++;
        } else {
            insertLast(B, tailB, 0);
            sizeB++;
        }
    }
}

ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    if (A == NULL && B == NULL)
        return NULL;

    addUpZeros(A, B);

    int carry = 0;
    ListNode * head = A;
    ListNode * cur;
    while(head != NULL) {
        cur = head;
        head = head->next;

        int sum = cur->val + B->val + carry;
        cur->val = sum % 10;
        carry = sum / 10;

        B = B->next;
    }

    if (carry != 0) {
        cur->next = new ListNode(carry);
        cur = cur->next;
    }

    // If input contains no leading zeros,
    // then does the sum

    return A;
}

// Solution 2 (short version) - no need to add leading zeros
// but need to allocate memory to store the sum
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    if (A == NULL) return B;
    if (B == NULL) return A;

    int sum = A->val + B->val;
    int carry = sum / 10;
    ListNode * head = new ListNode(sum % 10);
    ListNode * tail = head;
    A = A->next;
    B = B->next;

    while(A || B || carry) {
        sum = (A ? A->val : 0) + (B ? B->val : 0) + carry;
        tail->next = new ListNode(sum % 10);
        carry = sum / 10;

        if (A) A = A->next;
        if (B) B = B->next;
        tail = tail->next;
    }

    // If input contains no leading zeros,
    // then does the sum

    return head;
}
