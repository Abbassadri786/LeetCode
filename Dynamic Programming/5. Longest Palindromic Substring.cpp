class Solution {
public:
    string longestPalindrome(string s1) {

        int n = s1.length();

        // Create reversed string
        string s2 = s1;
        reverse(s2.begin(), s2.end());

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        int maxLen = 0;
        int endIndex = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){

                if(s1[i-1] == s2[j-1]){

                    dp[i][j] = 1 + dp[i-1][j-1];

                    // Original index in reversed string
                    int originalIndex = n - j;

                    // Check if substring positions match
                    if(originalIndex + dp[i][j] - 1 == i-1){

                        if(dp[i][j] > maxLen){
                            maxLen = dp[i][j];
                            endIndex = i-1;
                        }
                    }
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }

        return s1.substr(endIndex - maxLen + 1, maxLen);
    }
};
