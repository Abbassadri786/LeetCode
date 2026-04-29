/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string using BFS (level-order traversal)
    string serialize(TreeNode* root) {
        
        if(!root) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curNode = q.front();
            q.pop();

            // If node is NULL, store marker "#"
            if(curNode == NULL) {
                s.append("#,");
            }
            else {
                // Store current node value
                s.append(to_string(curNode->val) + ',');

                // Push children (even if NULL to preserve structure)
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }

        return s;
    }

    // Decodes the string back to binary tree using BFS
    TreeNode* deserialize(string data) {
        
        // If input string is empty, return NULL tree
        if(data.size() == 0) return NULL;

        stringstream s(data);
        string str;

        // First value is root
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();

            // Process left child
            getline(s, str, ',');
            if(str == "#"){
                node->left = NULL;
            }
            else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            // Process right child
            getline(s, str, ',');
            if(str == "#"){
                node->right = NULL;
            }
            else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};

// Usage:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
