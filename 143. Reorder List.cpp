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
