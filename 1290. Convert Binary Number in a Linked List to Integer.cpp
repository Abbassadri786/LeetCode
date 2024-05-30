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
    int getDecimalValue(ListNode* head) {
        int num = 0;
        
        while (head != nullptr) {
            // Left shift the current number by 1 to make space for the next bit
            num = (num << 1) | head->val;
            // Move to the next node
            head = head->next;
        }
        
        return num;
    }
};
