class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
         // Find the maximum element in the array
        int maxElement = *max_element(nums.begin(), nums.end());
        
        // Calculate the sum of the maximum element incremented k times
        int maxSum = 0;
        for (int i = 0; i < k; ++i) {
            maxSum += maxElement;
            maxElement++;
        }

        return maxSum;
    }
};
