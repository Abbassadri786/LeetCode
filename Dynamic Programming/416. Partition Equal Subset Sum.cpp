// Approach using Bottom Up Tabulation method, in odd sum case partioning is impossible
// Similar to 0/1 Knapsack and extension of subset sum
class Solution {
private:
    bool subsetSum(vector<int>& nums, int sum){
        int n = nums.size();
        // initializing DP
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
        // base condition
        for(int i=0; i< n+1; i++){
            dp[i][0] = true;
        }
        // filling up the table
        for(int i=1; i < n+1; i++){
            for(int j=1; j < sum+1; j++){
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][sum];
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto &i: nums){
            sum += i;
        }

        if(sum%2 != 0){
            return false;
        }
        return subsetSum(nums, sum/2);
    }
};
