// Approach 1 - Traverse each node via BST Traversal
class Solution {
private:
    int sum = 0;

    void dfs(TreeNode* node, int low, int high) {
        if(node == nullptr) {
            return;
        }

        // Traverse left subtree
        dfs(node->left, low, high);

        // Add current node if it lies within the range
        if(node->val >= low && node->val <= high) {
            sum += node->val;
        }

        // Traverse right subtree
        dfs(node->right, low, high);
    }

public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        dfs(root, low, high);
        return sum;
    }
};
