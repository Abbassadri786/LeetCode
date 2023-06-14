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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* AnsHead = new ListNode(-1);
        ListNode* AnsTail = AnsHead;

        ListNode* fast = head;
        int sum = 0;
        while(fast != NULL){
            //Agar fast != 0 he tab tak Sum calculate karo
            if(fast -> val != 0){
                sum += fast -> val;
            }
            //Agar fast == 0 ho jaaye to AnsTail ko update karo
            else if(sum != 0){
                ListNode* newNode = new ListNode(sum);
                AnsTail -> next = newNode;
                AnsTail = newNode;
                // Reset kardo sum ko
                sum = 0;
            }
            fast = fast -> next;
        }
        // Delete karo pehli Node = -1

        return AnsHead -> next;
        
        
    }
};

//Method 2 : Known to be more efficient 

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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* AnsHead = new ListNode(-1);
        ListNode* AnsTail = AnsHead;

        ListNode* slow = head;
        ListNode* fast = slow -> next;
        int sum = 0;
        while(fast != NULL){
            //Agar fast != 0 he tab tak Sum calculate karo
            if(fast != NULL && fast -> val != 0 && slow -> val == 0){
                sum += fast -> val;
                fast = fast -> next;
            }
            //Agar fast == 0 ho jaaye to AnsTail ko update karo
            else if(fast != NULL && fast-> val == 0 && sum != 0){
                ListNode* newNode = new ListNode(sum);
                AnsTail -> next = newNode;
                AnsTail = newNode;
                // Reset kardo sum ko
                sum = 0;
                slow = fast;
                fast = fast -> next;
            }
        }
        // Delete karo pehli Node = -1
        ListNode* temp = AnsHead;
        AnsHead = AnsHead -> next;
        temp -> next = NULL;

        return AnsHead;
    }
};
