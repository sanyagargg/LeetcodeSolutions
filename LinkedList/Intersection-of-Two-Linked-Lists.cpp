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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;  // If either list is empty, no intersection
        
        ListNode *pA = headA;
        ListNode *pB = headB;
        
        // Traverse both lists. When a pointer reaches the end of a list, redirect it to the head of the other list
        while (pA != pB) {
            pA = (pA == NULL) ? headB : pA->next;
            pB = (pB == NULL) ? headA : pB->next;
        }
        
        return pA;  // If pA == pB, it means we found the intersection, otherwise, it will be NULL
    }
};
