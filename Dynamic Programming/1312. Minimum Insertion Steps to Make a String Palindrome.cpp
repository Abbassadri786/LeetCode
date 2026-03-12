class Solution {
    // This question is from Longest Common Subsequence where
    // To make a String Palindrome in min op = (Total Length - LCS)
public:
    int minInsertions(string s1) {
        int n = s1.length();
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        
        // dp[i][j] = length of LCS of first i characters of s1 and first j characters of s2
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        // Build LCS DP table
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                
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
        
        return (n - dp[n][n]);
    }
};
