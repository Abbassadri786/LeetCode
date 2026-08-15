class Solution {
public:
    int minimumCoins(vector<int>& prices) {

        int n = prices.size();

        // dp[i] = minimum coins needed to get all fruits
        // starting from fruit i
        vector<int> dp(n + 1, 0);

        // Last fruit must be bought directly
        dp[n - 1] = prices[n - 1];

        for(int i = n - 2; i >= 0; i--) {

            int minCost = INT_MAX;

            // Buying fruit i allows us to get the next i+1 fruits for free.
            // So the next fruit we actually need to pay for can be
            // anywhere from i+1 to 2*i+2.
            for(int j = i + 1; j <= min(2 * i + 2, n - 1); j++) {
                minCost = min(minCost, dp[j]);
            }

            // Pay for current fruit + minimum cost for remaining fruits
            dp[i] = prices[i] + minCost;
        }

        return dp[0];
    }
};
