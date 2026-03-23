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
    // Approach : 2 Using Inorder Traversal as on node's left we have small elem and on it's right we have larger elem
    // Initialize a variable, cnt = 0;
    // Do an Inorder traversal and instead of saving node->val in vector do a cnt++, denoting that we have encountered cnt th smallest element.
    // Return node->val once cnt == k.
private:
    void inOrderTraversal(TreeNode* node, int &cnt, int &ans, int k){
        if(node == NULL) return;

        inOrderTraversal(node -> left, cnt, ans, k);
        cnt++;
        if(cnt == k){
            ans = node->val;
            return;
        }
        inOrderTraversal(node -> right, cnt, ans, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int ans;
        inOrderTraversal(root, cnt, ans, k);
        return ans;
    }
};
