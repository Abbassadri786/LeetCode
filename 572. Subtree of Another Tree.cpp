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
    // Check if two trees are identical
    bool isSame(TreeNode* root, TreeNode* subRoot){

        // both null → match
        if(!root && !subRoot) return true;

        // one null or value mismatch → not match
        if(!root || !subRoot || root->val != subRoot->val)
            return false;

        // check left and right subtree
        return isSame(root->left, subRoot->left) &&
               isSame(root->right, subRoot->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        // base case
        if(!root) return false;

        // if current node matches, check full subtree
        if(root->val == subRoot->val && isSame(root, subRoot))
            return true;

        // otherwise search in left and right subtree
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};
