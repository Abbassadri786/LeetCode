/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    Node* cloneUtil(Node* node, unordered_map<Node*, Node*>& mp){
        Node* newNode = new Node(node -> val);
        mp[node] = newNode;
        for(auto neighbor : node->neighbors){
            if(mp.find(neighbor) == mp.end()){
                // create one
                (newNode->neighbors).push_back(cloneUtil(neighbor, mp));
            }
            else{
                (newNode->neighbors).push_back(mp[neighbor]);
            }
        }
        return newNode;
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*, Node*> mp;
        return cloneUtil(node, mp);
    }
};
