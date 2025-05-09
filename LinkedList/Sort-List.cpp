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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head; // If the list is empty or has only one element, return the list as is.
        }

        // Step 1: Split the list into two halves
        ListNode* mid = getMiddle(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = nullptr; // Split the list into two parts

        // Step 2: Recursively sort both halves
        left = sortList(left);
        right = sortList(right);

        // Step 3: Merge the sorted halves
        return merge(left, right);
    }

private:
    // Function to find the middle node of the list
    ListNode* getMiddle(ListNode* head) {
        if (!head) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        // Move fast by 2 steps and slow by 1 step until fast reaches the end
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow; // Slow is at the middle
    }

    // Function to merge two sorted lists
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(0); // Dummy node to simplify code
        ListNode* current = dummy;

        while (left && right) {
            if (left->val < right->val) {
                current->next = left;
                left = left->next;
            } else {
                current->next = right;
                right = right->next;
            }
            current = current->next;
        }

        // Append the remaining nodes
        if (left) current->next = left;
        if (right) current->next = right;

        return dummy->next; // Return the sorted merged list starting from the first valid node
    }
};
