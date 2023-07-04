class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();
        int total_elem = row*col;

        int startingRow = 0;
        int startingCol = 0;
        int endingRow = row - 1;
        int endingcol = col - 1;

        int count = 0;
        while(count < total_elem){
            for(int i = startingCol; i <= endingcol && count < total_elem; i++){
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;
            for(int i = startingRow; i <= endingRow && count < total_elem; i++){
                ans.push_back(matrix[i][endingcol]);
                count++;
            }
            endingcol--;
            for(int i = endingcol; i >= startingCol && count < total_elem; i--){
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;
            for(int i = endingRow; i >= startingRow && count < total_elem; i--){
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans;
    }
};
