// Solution 1: Recursive
// O(N/2) in time and space
class Solution {
public:
    int getLength(ListNode* head) {
        int length = 0;
        while(head) {
            length++;
            head = head->next;
        }
        return length;
    }
    
    bool isPalindromeRecurse(ListNode* node, int length, ListNode*& iNode) {
        if (length == 0) { iNode = node; return true; }
        if (length == 1) { iNode = node->next; return true; }
        
        if (!isPalindromeRecurse(node->next, length - 2, iNode))
            return false;
        
        if (node->val == iNode->val) {
            iNode = iNode->next;
            return true;
        }
        return false;
    }
    
    bool isPalindrome(ListNode* head) {
        int length = getLength(head);
        ListNode* iNode;
        return isPalindromeRecurse(head, length, iNode);
    }
};

// Solution 2: Compare list with reversed list
// O(N) in space and O(2N) in time
class Solution {
public:
    ListNode* reverseAndClone(ListNode* node) {
        ListNode* head = NULL;
        while(node) {
            ListNode* n = new ListNode(node->val);
            n->next = head;
            head = n;
            node = node->next;
        }
        return head;
    }
    
    bool isEqual(ListNode* one, ListNode* two) {
        while(one && two) {
            if (one->val != two->val)
                return false;
            one = one->next;
            two = two->next;
        }
        return one == NULL && two == NULL;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* reversed = reverseAndClone(head); 
        return isEqual(head, reversed);
    }
};

// Solution 3: middle node + stack
// O(N) in time, O(N/2) in space
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // Find the middle node.
        ListNode* slow = head;
        ListNode* fast = head;
        stack<int> stack;
        while(fast && fast->next) {
            stack.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // If odd length, skip middle node.
        if (fast != NULL)
            slow = slow->next;
        
        while(slow) {
            if (stack.top() != slow->val)
                return false;
            stack.pop();
            slow = slow->next;
        }
        return true;
    }
};
