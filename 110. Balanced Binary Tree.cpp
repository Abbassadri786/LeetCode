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
// Checking balanced tree by doing operation abs(Left-Right) <= 1, hence using Height of the tree function
class Solution {
public:
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int Left = height(root -> left);
        int Right = height(root -> right);
        int ans = max(Left, Right) + 1;

        return ans;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }

        // 1 Case Hum solve karenge
        int Left = height(root -> left);
        int Right = height(root -> right);
        int diff = abs(Left - Right);

        int leftAns = isBalanced(root -> left);
        int rightAns = isBalanced(root -> right);

        if(diff <= 1 && leftAns && rightAns){
            return true;
        }
        else{
            return false;
        }

    }
};
