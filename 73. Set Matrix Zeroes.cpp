class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // Taking Dummy Row and Coloumn
        vector<int> row(n, 0);
        vector<int> col(m, 0);

        // Itrating through each coloum and row for 0 and mark it as 1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        // Now taking all the 0 containing row as 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (col[j] || row[i]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
