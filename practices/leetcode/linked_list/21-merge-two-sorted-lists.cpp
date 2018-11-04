// Solution 1: Dump iterative, completely create new list
// O(N+M) in time and space
class Solution {
public:
    void insertLast(ListNode*& head, ListNode*& tail, ListNode*& node) {
        if (head == NULL) {
            head = tail = new ListNode(node->val);
        } else {
            tail->next = new ListNode(node->val);
            tail = tail->next;
        }
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(l1 && l2) {
            if (l1->val < l2->val) {
                insertLast(head, tail, l1);
                l1 = l1->next;
            }
            else {
                insertLast(head, tail, l2);
                l2 = l2->next;
            }
        }
        while(l1) {
            insertLast(head, tail, l1);
            l1 = l1->next;
        }
        while(l2) {
            insertLast(head, tail, l2);
            l2 = l2->next;
        }
        return head;
    }
};

// Solution 2: Improvement for #1
class Solution {
public:
    void insertLast(ListNode*& head, ListNode*& tail, ListNode*& node) {
        if (head == NULL) {
            head = tail = new ListNode(node->val);
        } else {
            tail->next = new ListNode(node->val);
            tail = tail->next;
        }
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // Base case
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(l1 && l2) {
            if (l1->val < l2->val) {
                insertLast(head, tail, l1);
                l1 = l1->next;
            }
            else {
                insertLast(head, tail, l2);
                l2 = l2->next;
            }
        }
        tail->next = l1 ? l1 : l2;
        return head;
    }
};

// Solution 3: An inplace solution
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        ListNode* head = NULL;
        if (l1->val < l2->val) { head = l1; l1 = l1->next; }
        else                   { head = l2; l2 = l2->next; }
        
        ListNode* tail = head;
        
        while(l1 && l2) {
            if (l1->val < l2->val) { tail->next = l1; l1 = l1->next; }
            else                   { tail->next = l2; l2 = l2->next; }
            tail = tail->next;
        }
        
        tail->next = l1 ? l1 : l2;
        
        return head;
    }
};

// Solution 4: Recursive
// O(N+M) in time and space
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
};

Solution 5: Some next level pointer usage (from Linus)
// Inplace, O(1) in space, O(min(N, M)) in time
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode** pp = &head;
        while(l1 && l2) {
            if (l1->val < l2->val) { *pp = l1; l1 = l1->next; } 
            else                   { *pp = l2; l2 = l2->next; }
            pp = &((*pp)->next);
        }
        *pp = l1 ? l1 : l2;
        return head;
    }
};
