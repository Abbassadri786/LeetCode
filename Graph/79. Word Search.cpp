class Solution {
    // DFS approach: explore all 4 directions while matching characters
private:
    bool search(vector<vector<char>>& board, string &word,
                int i, int j, int idx, vector<vector<bool>> &visited){

        // If all characters are matched
        if(idx == word.length()) return true;

        // Boundary and validity checks
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()
           || visited[i][j] || board[i][j] != word[idx])
            return false;

        // Mark current cell visited
        visited[i][j] = true;

        // Explore all four directions
        bool found =
            search(board, word, i-1, j, idx+1, visited) ||
            search(board, word, i+1, j, idx+1, visited) ||
            search(board, word, i, j-1, idx+1, visited) ||
            search(board, word, i, j+1, idx+1, visited);

        // Backtrack
        visited[i][j] = false;

        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size(), m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m,false));

        // Try starting DFS from every cell
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(search(board, word, i, j, 0, visited))
                    return true;
            }
        }

        return false;
    }
};
