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
public:
    TreeNode* searchBST(TreeNode* root, int val) {
       // Base case: root is null or root's value is the target value
        if (root == nullptr || root->val == val) {
            return root;
        }
        
        // Since it's a BST, if the target value is less than the root's value, search in the left subtree
        if (val < root->val) {
            return searchBST(root->left, val);
        }
        
        // Otherwise, search in the right subtree
        return searchBST(root->right, val); 
    }
};
