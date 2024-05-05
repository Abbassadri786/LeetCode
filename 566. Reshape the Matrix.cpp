class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row = mat.size();
        int col = mat[0].size();
        if(r*c != row*col){
            return mat;
        }
        vector<vector<int>> res(r, vector<int>(c));
        int currRow = 0, currCol = 0;

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                res[i][j] = mat[currRow][currCol++];
                if(currCol == col){
                    currCol = 0;
                    currRow++;
                }
            }
        }

        return res;

    }
};
