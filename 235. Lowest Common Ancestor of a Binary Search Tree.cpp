class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || p==root || q==root) return root;

        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);

        if(left == NULL){
            return right;
        }
        else if(right == NULL){
            return left;
        }
        else{
            return root;
        }
    }
};

//Approach 2
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        while(root){

            // both nodes in left subtree
            if(p->val < root->val && q->val < root->val){
                root = root->left;
            }
            // both nodes in right subtree
            else if(p->val > root->val && q->val > root->val){
                root = root->right;
            }
            // split point → this is LCA
            else{
                return root;
            }
        }

        return NULL;
    }
};
