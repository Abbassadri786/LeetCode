class Solution {
public:

    // 8 directions
    int dirX[8] = {-1,-1,-1,0,0,1,1,1};
    int dirY[8] = {-1,0,1,-1,1,-1,0,1};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        // Source or destination blocked
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }

        vector<vector<int>> visited(n, vector<int>(n, 0));

        // {row, col, pathLength}
        queue<pair<pair<int,int>, int>> q;

        q.push({{0,0},1});
        visited[0][0] = 1;

        while(!q.empty()) {

            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;

            q.pop();

            // Reached destination
            if(row == n-1 && col == n-1) {
                return dist;
            }

            // Traverse all 8 neighbors
            for(int i = 0; i < 8; i++) {

                int newRow = row + dirX[i];
                int newCol = col + dirY[i];

                if(newRow >= 0 && newRow < n &&
                   newCol >= 0 && newCol < n &&
                   grid[newRow][newCol] == 0 &&
                   !visited[newRow][newCol]) {

                    visited[newRow][newCol] = 1;

                    q.push({{newRow,newCol}, dist + 1});
                }
            }
        }

        return -1;
    }
};
