/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // Slow and Fast Pointer approach
        ListNode* slow = head;
        ListNode* fast = head -> next;
        int count = 0;
        // Count number of nodes in a linked list
        while(slow != NULL){
            slow = slow -> next;
            count++;
        }
        // Now find Middle using Slow and Fast Pointer method
        slow = head;
        while(fast != NULL){
            fast = fast -> next;
            if(fast != NULL){
                fast = fast -> next;
                slow = slow -> next;
            }
        }
        // Odd Case
        if(count & 1){
            return slow;
        }
        // Even Case
        else{
            return slow->next;
        }
        
        
    }
};
