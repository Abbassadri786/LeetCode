class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int maxSum = INT_MIN, minSum = INT_MAX;
        int currentMax = 0, currentMin = 0;
        int n = nums.size();

        // Calculate total sum, maximum subarray sum, and minimum subarray sum
        for(int num : nums) {
            totalSum += num;
            currentMax = max(num, currentMax + num);
            maxSum = max(maxSum, currentMax);
            currentMin = min(num, currentMin + num);
            minSum = min(minSum, currentMin);
        }

        // If all elements are negative, return the maximum element (which is the maximum subarray sum)
        if(maxSum < 0) {
            return maxSum;
        }

        // For circular subarray, subtract the minimum subarray sum from the total sum to get the maximum circular subarray sum
        return max(maxSum, totalSum - minSum);
    }
};
