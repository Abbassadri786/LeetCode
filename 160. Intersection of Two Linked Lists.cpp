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
        ListNode* first = headA;
        ListNode* second = headB;
        // Dono list ko saath me traverse kara or dekha scene kya he
        while(first != NULL && second != NULL){
            if(first == second){
                return first;
            }
            first = first -> next;
            second = second -> next;
        }
        // To check if Intersection is not their
        if(first == NULL && second == NULL && first != second) return NULL;

        if(first == NULL){
            // Here second is Bigger so find how much bigger it is
            int lenB = 0;
            while(second != NULL){
                lenB++;
                second = second -> next;
            }
            // Head ko utne se aage badha diya intersection mile
            while(lenB--){
                headB = headB -> next;
            }
        }
        else{
            // Here first is Bigger so find how much bigger it is
            int lenA = 0;
            while(first != NULL){
                lenA++;
                first = first -> next;
            }
            // Head ko utne se aage badha diya intersection mile
            while(lenA--){
                headA = headA -> next;
            }

        }
        // Traversal kiya through Head ptr to get intersection
        while(headA != headB){
            headA = headA -> next;
            headB = headB -> next;
        }
        // return any of them
        return headA;
        
    }
};
