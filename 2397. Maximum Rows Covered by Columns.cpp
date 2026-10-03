class Solution {
public:
    int ans = 0;

    // Count how many rows are completely covered.
    // A row is covered when all its 1s have been
    // converted to 0 by the selected columns.
    int covered(vector<vector<int>> &mat) {
        int cnt = 0;

        for (int i = 0; i < mat.size(); i++) {
            bool flag = 1;

            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1)
                    flag = 0;
            }

            if (flag)
                cnt++;
        }

        return cnt;
    }

    // Try every possibility of selecting/not selecting
    // each column.
    int solver(vector<vector<int>>& mat, int col, int i) {

        // Either we have selected required number of columns
        // or we have checked all columns.
        if (col == 0 || i == mat[0].size()) {
            int c = covered(mat);
            ans = max(ans, c);
            return c;
        }

        // Don't select current column.
        int x = solver(mat, col, i + 1);

        // Select current column.
        // Create a copy so changes don't affect other branches.
        vector<vector<int>> cmat = mat;

        // Selecting a column means all values in that
        // column become 0.
        for (int j = 0; j < mat.size(); j++) {
            cmat[j][i] = 0;
        }

        // Continue recursion with one less column to select.
        int y = solver(cmat, col - 1, i + 1);

        return max(x, y);
    }

    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        solver(matrix, numSelect, 0);
        return ans;
    }
};
