class Solution {
private:
    // Check whether a queen can be safely placed at (row, col)
    bool isPossible(int row, int col, vector<string>& board, int n){
        int dupRow = row;
        int dupCol = col;

        // Check upper-left diagonal
        while(row >= 0 && col >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row--;
            col--;
        }

        // Reset to original position
        row = dupRow;
        col = dupCol;

        // Check left side of the same row
        while(col >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            col--;
        }

        // Reset again
        row = dupRow;
        col = dupCol;

        // Check lower-left diagonal
        while(row < n && col >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row++;
            col--;
        }

        // Safe to place queen
        return true;
    }

    // Place queens column by column using backtracking
    void solve(int col, vector<string>& board,
               vector<vector<string>>& ans, int n){

        // All queens placed successfully
        if(col == n){
            ans.push_back(board);
            return;
        }

        // Try placing a queen in each row of the current column
        for(int row = 0; row < n; row++){
            if(isPossible(row, col, board, n)){
                // Place queen
                board[row][col] = 'Q';

                // Move to next column
                solve(col + 1, board, ans, n);

                // Backtrack: remove queen and try next row
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        // Initialize empty board with '.'
        vector<string> board(n, string(n, '.'));

        // Start placing queens from column 0
        solve(0, board, ans, n);
        return ans;
    }
};
