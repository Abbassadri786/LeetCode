class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            int size = q.size();
            vector<int> tmp;

            for(int i = 0; i < size; i++){

                TreeNode* node = q.front();
                q.pop();

                // store current node value
                tmp.push_back(node->val);

                // push left child
                if(node->left)
                    q.push(node->left);

                // push right child
                if(node->right)
                    q.push(node->right);
            }

            // add current level to answer
            ans.push_back(tmp);
        }

        return ans;
    }
};
