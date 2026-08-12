class Solution {
private:
    int countOverlap(vector<vector<int>>& A, vector<vector<int>>& B, int rowOff, int colOff){
        int n = A.size();
        int count = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int b_i = i + rowOff;
                int b_j = j + colOff;
                if(b_i < 0 || b_i >= n || b_j < 0 || b_j >= n){
                    continue;
                }
                if(A[i][j] == 1 && B[b_i][b_j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();

        int maxOverlap = 0;

        for(int rowOff = -n+1; rowOff < n; rowOff++){
            for(int colOff = -n+1; colOff < n; colOff++){
                int count = countOverlap(A, B, rowOff, colOff);

                maxOverlap = max(maxOverlap, count);
            }
        }

        return maxOverlap;
    }
};
