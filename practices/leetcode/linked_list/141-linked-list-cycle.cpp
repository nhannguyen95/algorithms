// Solution 1: Hash table
// O(N) in time and space
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> nodes;
        while(head) {
            if (nodes.find(head) != nodes.end())
                return true;
            nodes.insert(head);
            head = head->next;
        }
        return false;
    }
};

// Solution 2: Tortoise and Hare
// O(1) in space, O(N) in time
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};
