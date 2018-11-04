// Solution 1: Hash table, this code can be used if the list is unsorted
// O(N) in time and space
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode** pp = &head;
        ListNode* entry = head;
        unordered_set<int> seens;
        while(entry) {
            if (seens.find(entry->val) != seens.end()) {  // Remove this node
                *pp = entry->next;
            } else {
                pp = &((*pp)->next);
                seens.insert(entry->val);
            }
            entry = entry->next;
        }
        return head;
    }
};

// Solution 2:
// O(1) in space, O(N) in time
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode* c = head;
        ListNode* n = c->next;
        while(n) {
            if (c->val == n->val) {
                c->next = n->next;
                delete n;
            } else {
                c = c->next;
            }
            n = c->next;
        }
        return head;
    }
};
