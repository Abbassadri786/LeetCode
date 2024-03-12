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
    void flatten(TreeNode* root) {
        if (!root) return; // Base case: If the node is null, return.

        flatten(root->left); // Flatten the left subtree.
        flatten(root->right); // Flatten the right subtree.

        TreeNode* tempRight = root->right; // Store the current right subtree.
        root->right = root->left; // Move the left subtree to the right.
        root->left = NULL; // Set the left subtree to NULL.

        // Find the rightmost node of the current right subtree (which was originally the left subtree).
        TreeNode* curr = root;
        while (curr->right) {
            curr = curr->right;
        }

        // Attach the original right subtree to the rightmost node.
        curr->right = tempRight;
    }
};
