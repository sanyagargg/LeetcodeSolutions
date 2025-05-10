class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Create new nodes interleaved with original nodes
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = next;
            curr = next;
        }

        // Step 2: Assign random pointers to the new nodes
        curr = head;
        while (curr) {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        // Step 3: Separate the original and copied nodes
        curr = head;
        Node* copyHead = head->next;
        Node* copyCurr = copyHead;
        while (curr) {
            curr->next = curr->next->next;
            if (copyCurr->next)
                copyCurr->next = copyCurr->next->next;
            curr = curr->next;
            copyCurr = copyCurr->next;
        }

        return copyHead;
    }
};
