class Solution {
private:
    void bfs(queue<pair<int,int>>& q,
             vector<vector<int>>& vis,
             vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        int delr[4] = {-1,0,1,0};
        int delc[4] = {0,1,0,-1};

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nr = r + delr[i];
                int nc = c + delc[i];

                // move ONLY if next height >= current height
                if(nr >= 0 && nr < n && nc >= 0 && nc < m &&
                   !vis[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> pac(n, vector<int>(m, 0));
        vector<vector<int>> atl(n, vector<int>(m, 0));
        queue<pair<int,int>> pq, aq;

        // Pacific borders: top row + left col
        for(int i = 0; i < n; i++){
            pac[i][0] = 1; pq.push({i, 0});
        }
        for(int j = 0; j < m; j++){
            pac[0][j] = 1; pq.push({0, j});
        }

        // Atlantic borders: bottom row + right col
        for(int i = 0; i < n; i++){
            atl[i][m-1] = 1; aq.push({i, m-1});
        }
        for(int j = 0; j < m; j++){
            atl[n-1][j] = 1; aq.push({n-1, j});
        }

        bfs(pq, pac, heights);
        bfs(aq, atl, heights);

        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(pac[i][j] && atl[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};
