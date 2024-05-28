class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
         int sum = 0;
        int n = arr.size();
        
        for(int i = 0; i < n; i++) {
            // Loop through odd lengths
            for(int length = 1; i + length <= n; length += 2) {
                // Calculate the sum of the subarray starting at i with the current odd length
                for(int j = i; j < i + length; j++) {
                    sum += arr[j];
                }
            }
        }

        return sum;
    }
};
