class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Frequency map to count occurrences of each value
        unordered_map<int, int> valueCount;
        ListNode* temp = head;

        // First pass: Build frequency map based on values
        while (temp != nullptr) {
            valueCount[temp->val]++;
            temp = temp->next;
        }

        // Dummy node to simplify edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy; // Previous node pointer

        // Second pass: Remove nodes with values that appear more than once
        while (head != nullptr) {
            if (valueCount[head->val] > 1) {
                // If current value is a duplicate, skip this node
                prev->next = head->next;
            } else {
                // Otherwise, move prev forward
                prev = prev->next;
            }
            head = head->next;
        }

        // Save new head before deleting dummy
        ListNode* newHead = dummy->next;
        delete dummy; // Clean up dummy node
        return newHead;
    }
};
