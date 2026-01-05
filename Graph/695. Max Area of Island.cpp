class Solution {
private:
    void bfs(int row, int col,int &area,vector<vector<int>> &vis, vector<vector<int>>& grid ){
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row, col});
        area++;
        
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    area++;
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int maxArea = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    int area = 0;
                    bfs(i, j, area, vis, grid);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};
