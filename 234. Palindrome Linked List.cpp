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
// Approach:
// Find the middle of the list.
// Reverse the second half of the list.
// Compare the first half of the list with the reversed second half.
// Optionally, reverse the second half again to restore the list to its original order (though this is not strictly necessary unless you need to preserve the list structure).
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }


        ListNode *prev = nullptr, *curr = slow, *forward;
        while (curr) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        ListNode *left = head, *right = prev;
        while (right) { 
            if (left->val != right->val) {
                return false;
            }
            left = left->next;
            right = right->next;
        }
        return true;
    }
};
