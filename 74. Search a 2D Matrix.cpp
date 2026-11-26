// Approach : 1 using O(n^2)
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int n = matrix.size();
//         int m = matrix[0].size();

//         int i = 0, j = n-1;
//         while(i < m && j >= 0){
//             if(matrix[i][j] > target){
//                 j--;
//             }
//             else if(matrix[i][j] < target){
//                 i++;
//             }
//             else{
//                 return true;
//             }
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int n=(int)matrix.size();
       int m=(int)matrix[0].size();
            int low=0;
            int high=n*m-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                int row=mid/m;
                int col=mid%m;
                if(matrix[row][col]==target){
                    return true;
                }
                else if(target<matrix[row][col]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
        
       
       return false;
    }
};
