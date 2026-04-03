class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

        int n = board.size();
        int m = board[0].size();

        // check 8 directions
        int dx[8] = {-1,-1,-1, 0,0, 1,1,1};
        int dy[8] = {-1, 0, 1,-1,1,-1,0,1};

        //  mark transitions
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                int liveCnt = 0;

                for(int k = 0; k < 8; k++){
                    int newX = i + dx[k];
                    int newY = j + dy[k];

                    // check neighbor cell, not current cell
                    if(newX >= 0 && newX < n && newY >= 0 && newY < m &&
                       (board[newX][newY] == 1 || board[newX][newY] == 2)){
                        liveCnt++;
                    }
                }

                // apply rules
                if(board[i][j] == 1){
                    if(liveCnt < 2 || liveCnt > 3){
                        board[i][j] = 2; // live → dead
                    }
                }
                else{
                    if(liveCnt == 3){
                        board[i][j] = 3; // dead → live
                    }
                }
            }
        }

        // Step 2: finalize states
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(board[i][j] == 2) board[i][j] = 0;
                if(board[i][j] == 3) board[i][j] = 1;
            }
        }
    }
};
