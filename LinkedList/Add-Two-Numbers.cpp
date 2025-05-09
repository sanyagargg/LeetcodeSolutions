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
    // Helper function to convert a linked list to an integer
    int listToNumber(ListNode* head) {
        int num = 0;
        int place = 1;  // This will keep track of place values (1, 10, 100, etc.)
        
        while (head != nullptr) {
            num += head->val * place;
            place *= 10;  // Move to the next place value
            head = head->next;
        }
        
        return num;
    }
    
    // Helper function to convert an integer to a linked list
    ListNode* numberToList(int num) {
        if (num == 0) {
            return new ListNode(0);  // Special case for 0
        }
        
        ListNode* dummy = new ListNode(0); // Dummy node for easy manipulation
        ListNode* current = dummy;
        
        while (num > 0) {
            int digit = num % 10;  // Get the last digit
            current->next = new ListNode(digit);
            current = current->next;
            num /= 10;  // Remove the last digit
        }
        
        return dummy->next;  // Return the result list (skip the dummy node)
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Convert the linked lists to integers
        int num1 = listToNumber(l1);
        int num2 = listToNumber(l2);
        
        // Add the two numbers
        int sum = num1 + num2;
        
        // Convert the sum back to a linked list
        return numberToList(sum);
    }
};
