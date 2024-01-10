class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        if (!root) return 0;  // Handle empty tree

        unordered_map<int, vector<int>> adjacencyList;
        buildAdjacencyList(root, adjacencyList);

        if (adjacencyList.find(start) == adjacencyList.end()) return 0;  // Start node not found

        return bfs(adjacencyList, start);
    }

private:
    void buildAdjacencyList(TreeNode* root, unordered_map<int, vector<int>>& adjacencyList) {
        if (!root) return;

        if (root->left) {
            adjacencyList[root->val].push_back(root->left->val);
            adjacencyList[root->left->val].push_back(root->val);
            buildAdjacencyList(root->left, adjacencyList);
        }

        if (root->right) {
            adjacencyList[root->val].push_back(root->right->val);
            adjacencyList[root->right->val].push_back(root->val);
            buildAdjacencyList(root->right, adjacencyList);
        }
    }

    int bfs(const unordered_map<int, vector<int>>& adjacencyList, int start) {
        queue<int> q;
        unordered_set<int> visited;
        int minutes = 0;

        q.push(start);
        visited.insert(start);

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                int current = q.front();
                q.pop();

                for (int neighbor : adjacencyList.at(current)) {
                    if (visited.find(neighbor) == visited.end()) {
                        q.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
            }

            if (!q.empty()) {
                minutes++;
            }
        }

        return minutes;
    }
};class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        if (!root) return 0;  // Handle empty tree

        unordered_map<int, vector<int>> adjacencyList;
        buildAdjacencyList(root, adjacencyList);

        if (adjacencyList.find(start) == adjacencyList.end()) return 0;  // Start node not found

        return bfs(adjacencyList, start);
    }

private:
    void buildAdjacencyList(TreeNode* root, unordered_map<int, vector<int>>& adjacencyList) {
        if (!root) return;

        if (root->left) {
            adjacencyList[root->val].push_back(root->left->val);
            adjacencyList[root->left->val].push_back(root->val);
            buildAdjacencyList(root->left, adjacencyList);
        }

        if (root->right) {
            adjacencyList[root->val].push_back(root->right->val);
            adjacencyList[root->right->val].push_back(root->val);
            buildAdjacencyList(root->right, adjacencyList);
        }
    }

    int bfs(const unordered_map<int, vector<int>>& adjacencyList, int start) {
        queue<int> q;
        unordered_set<int> visited;
        int minutes = 0;

        q.push(start);
        visited.insert(start);

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                int current = q.front();
                q.pop();

                for (int neighbor : adjacencyList.at(current)) {
                    if (visited.find(neighbor) == visited.end()) {
                        q.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
            }

            if (!q.empty()) {
                minutes++;
            }
        }

        return minutes;
    }
};
