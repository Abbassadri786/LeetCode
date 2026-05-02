// Approach: Use DFS + memoization to compute longest increasing path from each cell, avoiding recomputation.
class Solution {
public:
    int rows, cols;
    // cache[i][j] stores longest increasing path starting from (i, j)
    vector<vector<int>> cache;
    int dirs[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

    int dfs(vector<vector<int>>& matrix, int i, int j){
        
        // If already computed, return cached result
        if(cache[i][j]) return cache[i][j];
        
        int max_dir_path = 0;

        // Explore all 4 directions
        for(auto dir: dirs){
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            // Check bounds + strictly increasing condition
            if(new_i >= 0 && new_j >= 0 && 
               new_i < rows && new_j < cols && 
               matrix[i][j] < matrix[new_i][new_j]){

                max_dir_path = max(max_dir_path, dfs(matrix, new_i, new_j));
            }
        }

        // Include current cell (+1)
        cache[i][j] = max_dir_path + 1;
        return cache[i][j]; 
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rows = matrix.size();
        if(!rows) return 0;

        cols = matrix[0].size();

        // Initialize cache with 0 (means not computed yet)
        cache = vector<vector<int>>(rows, vector<int>(cols, 0));

        int max_path = 0;

        // Try DFS from every cell
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                max_path = max(max_path, dfs(matrix, i, j));
            }
        }

        return max_path; 
    }
};
