class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        // Matrix + Histogram Heights + Greedy Sorting
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;

        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                //First convert each column into heights of consecutive 1s
                if(matrix[i][j] == 1){
                    matrix[i][j] += matrix[i-1][j];
                }
            }
        }

        for(int i=0; i<n; i++){
            //So for every row we can sort heights in descending order.
            sort(matrix[i].rbegin(), matrix[i].rend());
            // Try every possible width
            for(int j=0; j<m; j++){
                ans = max(ans, matrix[i][j] * (j+1));
            }
        }

        return ans;
    }
};
