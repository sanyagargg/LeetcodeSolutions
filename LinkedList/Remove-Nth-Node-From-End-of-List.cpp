/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast ahead by n + 1 steps
        for (int i = 1; i <= n + 1; i++) {
            fast = fast->next;
        }

        // Move both fast and slow until fast reaches the end
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the nth node from the end
        slow->next = slow->next->next;

        return dummy->next;
    }
};
