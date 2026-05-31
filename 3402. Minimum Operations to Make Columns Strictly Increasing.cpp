class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        int operations = 0;

        // Traverse column by column
        for(int col = 0; col < cols; col++) {

            // Compare adjacent elements in current column
            for(int row = 1; row < rows; row++) {

                // If current value is not strictly greater
                if(grid[row][col] <= grid[row - 1][col]) {

                    // Minimum value needed to make it greater
                    int required = grid[row - 1][col] + 1;

                    operations += required - grid[row][col];

                    // Update grid for future comparisons
                    grid[row][col] = required;
                }
            }
        }

        return operations;
    }
};
