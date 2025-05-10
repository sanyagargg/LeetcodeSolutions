class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Find the length of the list and the tail
        int len = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }

        // Step 2: Make the list circular
        tail->next = head;

        // Step 3: Find the new tail and new head
        k = k % len;
        int stepsToNewTail = len - k;
        ListNode* newTail = tail;
        while (stepsToNewTail--) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};

