class Solution {
    // This question is from Longest Common Subsequence where
    // (s1 - LCS) + (s2 - LCS) = so return s1 + s2 - 2*LCS
public:
    int minDistance(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        
        // dp[i][j] = length of LCS of first i characters of s1 and first j characters of s2
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        // Build LCS DP table
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                
                // If characters match → include this character in LCS
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    // Otherwise take best by skipping one character
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return (m + n - 2*dp[n][m]);
    }
};
