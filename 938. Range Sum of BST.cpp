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

//Approach 2 - avoid traversing unnecessary branches.
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {

        if(root == nullptr) {
            return 0;
        }

        // Current node is smaller than range,
        // so skip the entire left subtree
        if(root->val < low) {
            return rangeSumBST(root->right, low, high);
        }

        // Current node is larger than range,
        // so skip the entire right subtree
        if(root->val > high) {
            return rangeSumBST(root->left, low, high);
        }

        // Current node lies within the range
        return root->val +
               rangeSumBST(root->left, low, high) +
               rangeSumBST(root->right, low, high);
    }
};  
