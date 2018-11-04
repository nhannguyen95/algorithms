/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Solution 1
ListNode* Solution::swapPairs(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    // Swap the first 2 element
    ListNode * ans = head->next;
    head->next = ans->next;
    ans->next = head;

    while(head->next != NULL && head->next->next != NULL) {
        ListNode * dummy = head->next;
        head->next = dummy->next;
        dummy->next = head->next->next;
        head->next->next = dummy;

        head = dummy;
    }

    return ans;
}

// Solution 2
ListNode* swap(ListNode * next1, ListNode * next2) {
  next1->next = next2->next;
  next2->next = next1;
  return next2;
}

ListNode* Solution::swapPairs(ListNode* head) {
  ListNode * start = new ListNode(0);  // make head no longer a special case
  start->next = head;

  ListNode * cur = start;
  while(cur->next != NULL && cur->next->next != NULL) {
    cur->next = swap(cur->next, cur->next->next);
    cur = cur->next->next;
  }

  return start->next;
}
