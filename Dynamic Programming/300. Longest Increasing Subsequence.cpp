class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        // dp[i] = length of LIS ending at index i
        // Initially every element itself is a subsequence of length 1
        vector<int> dp(n, 1);

        // Variable to track the overall maximum LIS length
        int maxLen = 1;

        // Traverse each element as the ending element of LIS
        for(int i = 0; i < n; i++){

            // Check all previous elements
            for(int j = 0; j < i; j++){

                // If current element can extend the increasing subsequence
                if(nums[i] > nums[j]){

                    // Update LIS length ending at i
                    dp[i] = max(dp[i], dp[j] + 1);
                }

                // Update the global maximum LIS length
                maxLen = max(maxLen, dp[i]);
            }
        }

        // Return the longest increasing subsequence length
        return maxLen;
    }
};
