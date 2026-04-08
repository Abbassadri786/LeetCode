class Solution {
private:
    // This function returns the maximum path sum starting from this node
    int maxPathDown(TreeNode* node, int &maxi){
        
        // Base case: if node is NULL, no contribution
        if(node == NULL){
            return 0;
        }

        // Recursively calculate max path sum from left subtree
        // Ignore negative values (take 0 instead)
        int left = max(0, maxPathDown(node->left, maxi));

        // Same for right subtree
        int right = max(0, maxPathDown(node->right, maxi));

        // Case 1: Path passes THROUGH this node (left + node + right)
        // This could be the answer, so update global maximum
        maxi = max(maxi, left + right + node->val);

        // Case 2: Return the maximum SINGLE path to parent
        // We can only choose one side (no split allowed upward)
        return max(left, right) + node->val;
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN; // Stores final answer
        maxPathDown(root, maxi);
        return maxi;
    }
};
