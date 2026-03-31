// Approach 1: Storing whole list in vector then traversing it from start and end simultaneously
class Solution {
public:
    void reorderList(ListNode* head) {

        if(!head || !head->next) return;

        // Step 1: store nodes in vector
        vector<ListNode*> nodes;
        ListNode* temp = head;

        while(temp){
            nodes.push_back(temp);
            temp = temp->next;
        }

        // Step 2: reorder using two pointers
        int i = 0, j = nodes.size() - 1;

        while(i < j){
            nodes[i]->next = nodes[j];
            i++;

            if(i == j) break;

            nodes[j]->next = nodes[i];
            j--;
        }

        // last node should point to NULL
        nodes[i]->next = NULL;
    }
};

//Approach 2: a) Use slow and fast pointer and find out the middle
// b) now do slow -> next = null and then reverse the second half
// c) // Reorder logic: the first->next gets connected to second (which is now at prev)

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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head;
        //middle of the linked list
        while(fast && fast->next){
            slow = slow-> next;
            fast = fast-> next -> next;
        }
        // In case of odd length, the second half starts at slow->next
        ListNode* second = slow-> next;
        slow -> next = nullptr;

        // Reverse the second half (mid+1 onwards)
        ListNode* curr = second;
        ListNode* prev = nullptr;
        while(curr != NULL){
            ListNode* next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        // Reorder logic the first->next gets connected to second (which is now at prev)
        ListNode* first = head;
        second  = prev;

        while(second){
            ListNode* temp1 = first -> next;
            ListNode* temp2 = second -> next;

            first -> next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};
