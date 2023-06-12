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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = curr -> next;
        ListNode* check = head;
        int count = 0;
        
        // Check if there are enough nodes remaining to reverse
        while (count < k && check != NULL) {
            check = check->next;
            count++;
        }
        
        // If there are enough nodes, reverse the group
        if (count == k) {
            count = 0;
            
            // Reverse the k nodes
            while (curr != NULL && count < k) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                count++;
            }
            
            // Recursively reverse the next k nodes
            if (next != NULL) {
                head->next = reverseKGroup(next, k);
            }
            
            // 'prev' is the new head of the reversed group
            return prev;
        } else {
            // If there are not enough nodes, return the head as is
            return head;
        }
    }
};
