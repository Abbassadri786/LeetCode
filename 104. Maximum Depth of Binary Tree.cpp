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
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        // left side ko poora traverse karo
        int leftHeight = maxDepth(root -> left);
        // right side ko poora traverse karo
        int rightHeight = maxDepth(root -> right);
        // Find max of the two + root node(mandatory)
        int ans = max(leftHeight, rightHeight) +1;

        return ans;

    }
};
