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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;
        // Lenghth find karo Linked List ki
        while(temp){
            temp = temp -> next;
            len++;
        }
        //starting node wala case me head ko aage badhaao
        //Remaining cases me len - n tk traverse karrke delete karo
        temp = head;
        if(len == n){
            ListNode* toDelete = temp;
            head = head -> next;
            delete toDelete;
            return head;
        }
        // Aage se node ki position se Ek kam
        int traverse = len - n -1;
        //Nth node takk Traverse karro
        while(traverse--){
            temp = temp -> next;
        }
        ListNode* toDelete = temp -> next;
        temp -> next = temp -> next -> next;
        delete toDelete;

        return head;
    }
};
