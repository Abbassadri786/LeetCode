class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle(numRows);

        for (int i = 0; i < numRows; ++i) {
            // The current row has i+1 elements
            triangle[i].resize(i + 1);
            
            // The first and last row elements are always 1
            triangle[i][0] = triangle[i][i] = 1;
            
            // Each triangle element (except the first and last of each row)
            // is equal to the sum of the elements above-and-to-the-left
            // and above-and-to-the-right
            for (int j = 1; j < i; ++j) {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }

        return triangle;
    }
};
