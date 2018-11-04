// Solution 1: Using hash table
// O(N) in space
// O(N) in time
// N = number of nodes
/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* head) {
    if (head == NULL) return NULL;

    // Copy 'next' pointers
    RandomListNode * cpHead = new RandomListNode(head->label);

    RandomListNode * cpDummy = cpHead;
    RandomListNode * dummy = head;

    unordered_map<RandomListNode *, RandomListNode *> M;
    M[dummy] = cpDummy;
    while(dummy->next) {
        cpDummy->next = new RandomListNode(dummy->next->label);

        cpDummy = cpDummy->next;
        dummy = dummy->next;

        M[dummy] = cpDummy;  // Mapping original nodes to copied nodes
    }

    // Copy 'random' pointers
    dummy = head;
    cpDummy = cpHead;
    while(dummy) {
        cpDummy->random = M[dummy->random];
        dummy = dummy->next;
        cpDummy = cpDummy->next;
    }

    return cpHead;
}
