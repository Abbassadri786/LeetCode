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
    bool solve(TreeNode* root, int currSum, int targetSum){
        if(root == NULL){
            return false;
        }

        currSum += root -> val;
        if(root -> left == NULL && root -> right == NULL){
            if(currSum == targetSum){
                return true;
            }
            return false;
        } 
        bool Left = solve(root->left, currSum, targetSum);
        bool Right = solve(root->right, currSum, targetSum);

        return Left || Right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root,0,targetSum);
        
    }
};
