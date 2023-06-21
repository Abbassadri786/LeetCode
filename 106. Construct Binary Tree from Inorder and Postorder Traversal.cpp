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
    int findPosition(vector<int>& inorder, int size, int element){

        for(int i = 0; i < size; i++){
            if(element == inorder[i]){
                return i;
                break;
            }
        }
        return -1;
    }
    TreeNode* buildBT(vector<int>& inorder, vector<int>& postorder, int &postIndex, int size, int indexAtStart, int indexAtEnd){
        //Base Case
        if(postIndex < 0 || indexAtStart > indexAtEnd){
            return NULL;
        }
        //Find the root element in the postOrder array and traverse according to inOrder array
        int element = postorder[postIndex--];
        TreeNode* root = new TreeNode(element);

        int pos = findPosition(inorder, size, element);
        //Root -> right solve reccursively
        root -> right = buildBT(inorder, postorder, postIndex, size, pos + 1, indexAtEnd);
        //Root -> left solve reccursively
        root -> left = buildBT(inorder, postorder, postIndex, size, indexAtStart, pos - 1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIndex = inorder.size()-1, indexAtStart = 0, indexAtEnd = inorder.size()-1, size = inorder.size();
        TreeNode* root = buildBT(inorder, postorder, postIndex, size, indexAtStart, indexAtEnd);
        return root;
    }
};
