class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int &perimeter) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        q.push({row, col});
        vis[row][col] = 1;

        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                //nr -> neighbour row cell & nc -> neighbour col of cell
                int nr = r + drow[i];
                int nc = c + dcol[i];

                // boundary → contributes to perimeter
                if(nr < 0 || nr >= n || nc < 0 || nc >= m){
                    perimeter++;
                }
                // water neighbor → contributes to perimeter
                else if(grid[nr][nc] == 0){
                    perimeter++;
                }
                // land & not visited → BFS
                else if(!vis[nr][nc]){
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int perimeter = 0;

        // exactly one island → start BFS from first land
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    bfs(i, j, grid, vis, perimeter);
                    return perimeter;
                }
            }
        }
        return 0;
    }
};
