class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9] = {0}, cols[9][9] = {0}, boxes[9][9] = {0};

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1'; // Convert char to int index (0-8)
                    int boxIndex = (i / 3) * 3 + j / 3;
                    
                    // Check if the number has already been used in the current row, column, or box
                    if (rows[i][num] || cols[j][num] || boxes[boxIndex][num])
                        return false;

                    // Mark the number as seen for the current row, column, and box
                    rows[i][num] = cols[j][num] = boxes[boxIndex][num] = 1;
                }
            }
        }

        return true; // All checks passed
    }
};
