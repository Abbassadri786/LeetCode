class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        // extra space so we can safely access i+1 and i+2
        vector<int> dp(n+2, 0);

        // fill DP from right to left
        for(int i = n-1; i >= 0; i--){

            // pick current house + skip next house
            int pick = nums[i] + dp[i+2];

            // skip current house
            int notPick = dp[i+1];

            dp[i] = max(pick, notPick);
        }

        return dp[0];
    }
};
