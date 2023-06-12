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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = curr -> next;

        while(curr != NULL){
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        // Step 1: Reverse both the Linked List
        // l1 = reverse(l1);
        // l2 = reverse(l2);

        // Add 2 Linked List
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        int carry = 0;

        while(l1 != NULL && l2 != NULL){
            // Calculate Sum including carry
            int sum = carry + l1 -> val + l2 -> val;
            // Find digit to create node for
            int digit = sum % 10;
            // Calculate carry generated
            carry = sum/10;

            // Create a new Node for the digit
            ListNode* newNode = new ListNode(digit);
            // Attach the new Node into ans Linked List
            if(ansHead == NULL){
                // First Node Insert kar rhe ho
                ansHead = newNode;
                ansTail = newNode;
            }
            else{
                ansTail -> next = newNode;
                ansTail = newNode;

            }
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        //Jab l1 ki length l2 se zyada ho
        while(l1 != NULL){
            int sum = carry + l1 -> val;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(digit);
            ansTail -> next = newNode;
            ansTail = newNode;
            l1 = l1 -> next;
        }
        //Jab l2 ki length l1 se zyada ho
        while(l2 != NULL){
            int sum = carry + l2 -> val;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(digit);
            ansTail -> next = newNode;
            ansTail = newNode;
            l2 = l2 -> next;
        }
        // Agar carry last me bach rha hoto
        while(carry != 0){
            int sum = carry;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode* newNode = new ListNode(digit);
            ansTail -> next = newNode;
            ansTail = newNode;
        }
        
        return ansHead;
        
    }
};
