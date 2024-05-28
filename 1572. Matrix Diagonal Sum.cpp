// Diagoals ka addition karrna he bass to single loop se kaam ho jaayega.

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            // add the element on the primary diagonal to the sum
            sum += mat[i][i];
            // add the element on the secondary diagonal to the sum  
            sum += mat[i][n-i-1];          
        }
        // if n is odd, we need to subtract the central element of the matrix, 
        // which is part of both the primary and secondary diagonals and was added twice.
        if (n % 2 != 0) {
            sum -= mat[n/2][n/2];
        }
        return sum;
    }
};
