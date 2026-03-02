// Approach 1: Using max Heap storing each element in heap, if size > k then pop and then return top k at last
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // Max heap to store k smallest elements
        priority_queue<int> maxH;

        // Traverse every element in the matrix
        for (auto &row : matrix) {
            for (auto &val : row) {
                maxH.push(val);

                // Keep heap size at most k
                if (maxH.size() > k) {
                    maxH.pop(); // remove largest among k+1 elements
                }
            }
        }

        // Top of max heap = kth smallest element
        return maxH.top();
    }
};

// Approach 2: Using Binary Search:
class Solution {
private:
    // Helper function to count how many elements in the matrix are less than or equal to a given target value.
    int countElements(vector<vector<int>>& matrix, int target){
        int n = matrix.size();

        int count = 0;

        // Start from bottom-left corner
        int row = n - 1, col = 0;

        while(row >= 0 && col < n){
            // If current element <= target, then all elements above in this column are also <= target
            // because column is sorted.
            if(matrix[row][col] <= target){
                // Add all elements from row 0 to current row
                count += (row + 1);
                // Move right to next column
                col++;
            }
            else{
                // Current element > target, so move upwards to find smaller elements
                row--;
            }
        }

        return count;
    }

public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
      
        // Binary search on value range (NOT indices)
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];

        int ans = 0;

        while(low <= high){
            int mid = low + (high - low) / 2;

            // Count how many elements are <= mid
            int count = countElements(matrix, mid);

            // If there are at least k elements <= mid, then mid could be the answer (or smaller)
            if(count >= k){
                ans = mid;
                high = mid - 1;
            }
            else{
                // If fewer than k elements <= mid, kth smallest must be larger
                low = mid + 1;
            }
        }
        return ans;
    }
};
