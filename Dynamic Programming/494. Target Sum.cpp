class Solution {
    // question similar to count of subset sum and is solved using bottom up Tabulation method
    // S1 - S2 = target
    // S1 + S2 = totalSum
    // 2*S1 = target + totalSum
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();
        int totalSum = 0;

        // Calculate total sum of array
        for(auto &i: nums){
            totalSum += i;
        }

        // If transformation not possible (odd or negative case)
        if((target + totalSum) % 2 != 0 || abs(target) > totalSum) 
            return 0;

        // Convert problem to subset sum count
        int exp = (target + totalSum) / 2;

        // DP table where dp[i][j] = ways to form sum j using first i elements
        vector<vector<int>> dp(n+1, vector<int>(exp+1, 0));

        // Base case: one way to form sum 0 (empty subset)
        for(int i=0; i<=n; i++){
            dp[i][0] = 1;
        }

        // Fill DP table
        for(int i=1; i<=n; i++){
            for(int j=0; j<=exp; j++){

                // If element can be included
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j - nums[i-1]] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }

            }
        }

        // Number of ways to form required subset sum
        return dp[n][exp];
    }
};
