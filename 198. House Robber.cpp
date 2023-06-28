class Solution {
public:
    int robHelper(vector<int>& nums, int n){
        // Base Case
        if(n >= nums.size()){
            return 0;
        }
        //Include Case
        int robAmt1 = robHelper(nums, n + 2) + nums[n];
        //Exclude Case
        int robAmt2 = robHelper(nums, n + 1) + 0;

        int ans = max(robAmt1, robAmt2);
        return ans;
    }

    int SolveMem(vector<int>& nums, int n, vector<int> &dp){
        // Base Case
        if(n < 0){
            return 0;
        }
        if( n == 0){
            return nums[0];
        }
  
        //Check if ans already exist
        if(dp[n] != -1){
            return dp[n];
        }
        //Include Case
        int include = SolveMem(nums, n - 2, dp) + nums[n];
        //Exclude Case
        int exclude = SolveMem(nums, n - 1, dp) + 0;
        //Store ans in DP
        dp[n] = max(include, exclude);
        return dp[n];
    }
    int SolveTab(vector<int>& nums, int n, vector<int> &dp){
        dp[0] = nums[0];

        for(int i = 1; i <= n; i++){
            int temp = 0;
            if(i - 2 >= 0){
                temp = dp[i-2];
            }
            //Include Case
            int include = temp + nums[i];
            //Exclude Case
            int exclude = dp[i - 1] + 0;
            //Store ans in DP
            dp[i] = max(include, exclude); 
        }
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n = nums.size() - 1;
        vector<int> dp(n+1, -1);
        return SolveTab(nums, n, dp);        
    }
};
