class Solution {
public:
    int SolveMem(vector<int>& coins, int amount, vector<int> &dp){
        //Base Case
        if(amount == 0){
            return 0;
        }
        if(amount < 0){
            return INT_MAX;
        }

        //Check If ans exist or not
        if(dp[amount] != -1){
            return dp[amount];
        }
        int mini = INT_MAX;
        for(int i = 0; i < coins.size(); i++){
            int ans = SolveMem(coins, amount - coins[i], dp);

            if(ans != INT_MAX){
                mini = min(mini, ans + 1);
            }
        }
        dp[amount] = mini;
        return mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        int ans = SolveMem(coins, amount, dp);

        if(ans == INT_MAX){
            return -1;
        }
        else{
            return ans;
        }
    }
};
