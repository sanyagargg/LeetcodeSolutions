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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect cycle using Floyd's Tortoise and Hare
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            // Cycle detected
            if (slow == fast) {
                ListNode* entry = head;

                // Step 2: Find entry point of the cycle
                while (entry != slow) {
                    entry = entry->next;
                    slow = slow->next;
                }

                return entry; // Entry point of the cycle
            }
        }

        return nullptr; // No cycle
    }
};
