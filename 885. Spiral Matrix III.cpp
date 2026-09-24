class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;

        int r = rStart;
        int c = cStart;
        ans.push_back({r,c});
        int steps = 1;
        int total = rows * cols;
// Crux of the story: four direction loops do run, but importantly, they continue updating r and c even when the position is outside the matrix. We only add the position to ans when it is inside the matrix.

        while(ans.size() < total){
            // move right
            for(int i=0; i < steps; i++){
                c++;
                if(r >= 0 && r < rows && c >= 0 && c < cols){
                    ans.push_back({r,c});
                }
            }
            //move down
            for(int i=0; i < steps; i++){
                r++;
                if(r >= 0 && r < rows && c >= 0 && c < cols){
                    ans.push_back({r,c});
                }
            }
            steps++;
            // move left
            for(int i=0; i < steps; i++){
                c--;
                if(r >= 0 && r < rows && c >= 0 && c < cols){
                    ans.push_back({r,c});
                }
            }
            //move up
            for(int i=0; i < steps; i++){
                r--;
                if(r >= 0 && r < rows && c >= 0 && c < cols){
                    ans.push_back({r,c});
                }
            }
            steps++;
        }

        return ans;
    }
};
