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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Base case: If the head is null or if k is 1, no need to reverse.
        if (!head || k == 1) return head;

        // First, find the length of the linked list.
        int length = 0;
        ListNode *temp = head;
        while (temp) {
            length++;
            temp = temp->next;
        }

        // If there are fewer than k nodes, return the original list
        if (length < k) return head;

        // Create a dummy node to handle edge cases
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prevGroupEnd = dummy;

        while (length >= k) {
            // Reverse k nodes in the current group
            ListNode *groupStart = prevGroupEnd->next;
            ListNode *groupEnd = groupStart;
            for (int i = 1; i < k; i++) {
                groupEnd = groupEnd->next;
            }
            ListNode *nextGroupStart = groupEnd->next;

            // Reverse the current group of k nodes
            ListNode *prev = nextGroupStart;
            ListNode *curr = groupStart;
            for (int i = 0; i < k; i++) {
                ListNode *next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // Connect the reversed group with the previous part of the list
            prevGroupEnd->next = prev;
            groupStart->next = nextGroupStart;

            // Move prevGroupEnd pointer to the end of the reversed group
            prevGroupEnd = groupStart;

            // Decrease the remaining length by k
            length -= k;
        }

        return dummy->next;
    }
};
