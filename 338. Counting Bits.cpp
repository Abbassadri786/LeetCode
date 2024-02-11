// Using O(NlogN) approach
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0; i<=n; i++){
            int cnt = 0;
            int num = i;
            while(num){
                if(num % 2 == 1){
                    cnt++;
                }
                num /= 2;
            }
        ans.push_back(cnt);
        }
        return ans;
        
    }
};

// Sol 2: Using O(N) approach
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            // Counting bits for number i using previously computed results
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }
};
