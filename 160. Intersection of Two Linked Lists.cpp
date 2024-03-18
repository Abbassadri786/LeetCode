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

        int lenA = 0, lenB = 0;
        ListNode *tempA = headA, *tempB = headB;
        while(tempA) {
            lenA++;
            tempA = tempA->next;
        }
        while(tempB) {
            lenB++;
            tempB = tempB->next;
        }
        

        tempA = headA;
        tempB = headB;
        
 
        while(lenA > lenB) {
            tempA = tempA->next;
            lenA--;
        }
        while(lenB > lenA) {
            tempB = tempB->next;
            lenB--;
        }
        
        while(tempA != tempB) {
            tempA = tempA->next;
            tempB = tempB->next;
        }

        return tempA;
    }
};
