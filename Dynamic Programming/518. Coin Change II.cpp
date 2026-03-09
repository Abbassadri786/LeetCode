class Solution {
public:
    int change(int amount, vector<int>& coins) {

        // dp[j] = number of ways to make sum j
        vector<long long> dp(amount + 1, 0);

        // base case: one way to form sum 0
        dp[0] = 1;

        // iterate coins (combination logic)
        for(int i = 0; i < coins.size(); i++){
            for(int j = coins[i]; j <= amount; j++){

                // unbounded knapsack transition
                dp[j] += dp[j - coins[i]];
            }
        }

        return (int)dp[amount];
    }
};
// Approach : 2 using Bottom up Tabulation
// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();

//         // use long long to avoid overflow during DP computation
//         vector<vector<long long>> dp(n+1, vector<long long>(amount+1, 0));

//         // base case: one way to make sum 0 (choose nothing)
//         for(int i = 0; i <= n; i++){
//             dp[i][0] = 1;
//         }

//         // fill DP table
//         for(int i = 1; i <= n; i++){
//             for(int j = 1; j <= amount; j++){
//                 if(coins[i-1] <= j){
//                     // unbounded knapsack: can reuse same coin
//                     dp[i][j] = dp[i][j - coins[i-1]] + dp[i-1][j];
//                 }
//                 else{
//                     dp[i][j] = dp[i-1][j];
//                 }
//             }
//         }

//         return (int)dp[n][amount];
//     }
// };
