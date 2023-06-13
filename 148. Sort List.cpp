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
    ListNode* merge(ListNode* head1, ListNode* head2) {
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    
    ListNode* AnsHead = NULL;
    ListNode* AnsTail = NULL;
    // First Traverse 1st node of both LL and Decide the Head and Tail to continue the process
    if(head1 -> val <= head2 -> val){
        AnsHead = head1;
        AnsTail = head1;
        head1 = head1 -> next;
    }
    else{
        AnsHead = head2;
        AnsTail = head2;
        head2 = head2-> next;
    }
    // Now Traverse Both LL and compare which node is smaller then insert that smaller node in AnsTail
    while(head1 != NULL && head2 != NULL){
        if(head1 -> val <= head2 -> val){
            AnsTail -> next = head1;
            AnsTail = head1;
            head1 = head1 -> next;
        }
        else if(head1 -> val > head2 -> val){
            AnsTail -> next = head2;
            AnsTail = head2;
            head2 = head2 -> next;
        }
        
    // Now Take care of remaining list if any one of two is left (Due to length difference)    
    }
    if(head1 == NULL){
        AnsTail -> next = head2;
    }
    if(head2 == NULL){
        AnsTail -> next = head1;
    }
    
    return AnsHead;       
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head ->next == NULL){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = NULL;
      
        // Find Mid using SLow and Fast method
        while(slow != NULL && fast != NULL){
            temp = slow;
            fast = fast-> next;
            if(fast != NULL){
                fast = fast -> next;
                slow = slow -> next;
            }
        }
        // Break LL into two halves
        ListNode* left = head;
        ListNode* right = temp -> next;        
        temp -> next = NULL;
      
        //Sort Recursively
        left = sortList(left);
        right = sortList(right);

        // Merge both Left and Right after sort
        ListNode* mergeList = merge(left,right);
        return mergeList;
    }
};
