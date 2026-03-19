// Approach 1: Using maxHeap and pop elem > k size
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void dfs(TreeNode* node, int k, priority_queue<int>& pq){
        if(!node) return;
        
        dfs(node -> left, k , pq);
        pq.push(node -> val);

        if(pq.size() > k){
            pq.pop();
        }

        dfs(node -> right, k , pq);

    }
public:
    int kthSmallest(TreeNode* root, int k) {
        // solve this question: iterate through each node and put into maxHeap and then pop k times and then return pq.top() 
        priority_queue<int> pq;
        dfs(root, k, pq);
        return pq.top();
    }
};
