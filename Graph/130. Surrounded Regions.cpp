class Solution {
    void bfs(int row, int col, vector<vector<char>> &board) {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int,int>> q;
        q.push({row, col});
        board[row][col] = '#';   // mark safe

        int delr[4] = {-1, 0, 1, 0};
        int delc[4] = {0, 1, 0, -1};

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + delr[i];
                int nc = c + delc[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m &&
                   board[nr][nc] == 'O'){
                    board[nr][nc] = '#';
                    q.push({nr, nc});
                }
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        if(n == 0) return;

        // 1️⃣ BFS from boundary O's
        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O') bfs(i, 0, board);
            if(board[i][m-1] == 'O') bfs(i, m-1, board);
        }
        for(int j = 0; j < m; j++){
            if(board[0][j] == 'O') bfs(0, j, board);
            if(board[n-1][j] == 'O') bfs(n-1, j, board);
        }

        // 2️⃣ Flip surrounded regions
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};
