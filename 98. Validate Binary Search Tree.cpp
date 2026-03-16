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
    bool check(TreeNode* node, long long minVal, long long maxVal){

        // Empty node is valid
        if(node == NULL) return true;

        // Current node must lie within valid range
        if(node->val <= minVal || node->val >= maxVal)
            return false;

        // Check left subtree (values must be smaller)
        // Check right subtree (values must be greater)
        return check(node->left, minVal, node->val) &&
               check(node->right, node->val, maxVal);
    }

public:
    bool isValidBST(TreeNode* root) {

        // Start with full possible range
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};
