// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;

//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
private:

    // Tracks current node in preorder traversal
    int preIdx = 0;

    // Tracks completed nodes in postorder traversal
    int postIdx = 0;

    TreeNode* construct(vector<int>& preorder, vector<int>& postorder) {

        // Create current root from preorder
        TreeNode* node = new TreeNode(preorder[preIdx++]);

        // Build left subtree if current subtree
        // is not yet completed in postorder
        if(node->val != postorder[postIdx]) {
            node->left = construct(preorder, postorder);
        }

        // Build right subtree if current subtree
        // is still not completed in postorder
        if(node->val != postorder[postIdx]) {
            node->right = construct(preorder, postorder);
        }

        // Current subtree completed
        postIdx++;

        return node;
    }

public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {

        return construct(preorder, postorder);
    }
};
