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
    void deleteNode(ListNode* node) {
        if (!node || !node->next) return;

        ListNode* deleteNode = node->next; // Node to be deleted
        node->val = deleteNode->val;       // Copy the value from the next node
        node->next = deleteNode->next;     // Skip the next node

        delete deleteNode; 
    }
};
