class Solution {
public:
    
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        
        // Calculate the length of the list
        int len = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            ++len;
        }
        
        // Connect the end of the list to the head to form a circle
        tail->next = head;
        
        // Calculate the effective rotations needed
        k = k % len;
        if (k == 0) {
            tail->next = nullptr; // Break the circle as no rotation is needed
            return head;
        }
        
        // Find the node just before the new head after the rotation
        int stepsToNewHead = len - k;
        ListNode* newTail = tail;
        while(stepsToNewHead--) {
            newTail = newTail->next;
        }
        
        // Set the new head and break the loop
        head = newTail->next;
        newTail->next = nullptr;
        
        return head;
    }
};
