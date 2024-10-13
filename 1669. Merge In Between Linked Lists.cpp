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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* head1 = list1;
        ListNode* head2 = list2;
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list1;
        int cnt = 0;
        while(cnt < b+1){
            if(cnt < a -1){
                ptr1 = ptr1 -> next;
            }
            ptr2 = ptr2 -> next;
            cnt++;
        }

        ptr1 -> next = head2;
        while(head2 -> next != NULL){
            head2 = head2 -> next;
        }
        head2 -> next = ptr2;
      
        return head1;

    }
};
