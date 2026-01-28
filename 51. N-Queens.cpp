// Approach 1: traversing in 3 directions using while to check if possible to place Queen
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



// Approach 2: using upperDiagonal, lowerDiagonal, leftrow hashing arrays
class Solution {
private:
    void solve( int col, vector<string>& board, vector<vector<string>>& ans, vector<int>& leftRow, vector<int>& lowerDiagonal, vector<int>& upperDiagonal, int n) {
        // All columns filled → valid board
        if (col == n) {
            ans.push_back(board);
            return;
        }

        // Try placing queen in each row of current column
        for (int row = 0; row < n; row++) {

            // O(1) safety check using hash arrays
            if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {

                // Place queen
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                // Recurse to next column
                solve(col + 1, board, ans, leftRow, lowerDiagonal, upperDiagonal, n);

                // Backtrack: remove queen
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        // Initialize empty board
        vector<string> board(n, string(n, '.'));

        // Hash arrays to track attacked rows & diagonals
        vector<int> leftRow(n, 0);
        vector<int> lowerDiagonal(2 * n - 1, 0);
        vector<int> upperDiagonal(2 * n - 1, 0);

        solve(0, board, ans, leftRow, lowerDiagonal, upperDiagonal, n);

        return ans;
    }
};
