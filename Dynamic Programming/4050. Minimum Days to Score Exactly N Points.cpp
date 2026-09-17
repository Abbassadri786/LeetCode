class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if (n == 0)
            return 0; // removes the unnecessary final skip

        if (dp[n] != -1)
            return dp[n];

        int ans = INT_MAX;

        for (int k = 1; k * (k + 1) / 2 <= n; k++) {
            int points = k * (k + 1) / 2;

            ans = min(ans, k + 1 + solve(n - points, dp));
        }

        return dp[n] = ans;
    }

    int minDays(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp) - 1 ;
    }
};
