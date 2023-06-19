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
    int findPosition(vector<int>& inorder, int element, int size){
        int pos;
        for(int i =0; i < size; i++){
            if(inorder[i] == element){
                pos = i;
                break;
            }
        }
        return pos;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& preorder, int &preIndex, int size, int indexAtStart, int indexAtEnd){
        // Base Case
        if(preIndex >= size || indexAtStart > indexAtEnd){
            return NULL;
        }
        
        //Create root node
        int element = preorder[preIndex++];
        TreeNode* root = new TreeNode(element);
        //Find pos of root Node in Inorder array
        int pos = findPosition(inorder, element, size);
        // Call reccursively to solve left and right part of the tree
        root->left = buildTree(inorder, preorder, preIndex, size, indexAtStart, pos-1);
      
        root->right = buildTree(inorder, preorder, preIndex, size, pos+1, indexAtEnd);
      
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0, indexAtStart = 0, indexAtEnd = inorder.size()-1, size = inorder.size();
        TreeNode* root = buildTree(inorder, preorder, preIndex, size, indexAtStart, indexAtEnd);
        return root;
    }
};
