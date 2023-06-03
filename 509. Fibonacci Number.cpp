class Solution {
public:
    int topDownFib(vector<int> &dp, int n){
        if( n==0 || n==1){
            return n;
        }
        //step 3: check if ans already exists
        if(dp[n] != -1){
            return dp[n];
        }
        //step 2: replace ans with dp[n]
        dp[n] = topDownFib(dp, n-1) + topDownFib(dp, n-2);
        return dp[n];

    }
    int bottomUpFib(int n){
       //step1: create a dp array
       vector<int> dp(n+1, -1);

       //step2:base case
       dp[0] = 0;
       if(n == 0) 
       return dp[0];
       dp[1] = 1;

       //step3: topDown approach me n kaise travel krra h 
       for(int i = 2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
       }

       return dp[n];
    }
    int fib(int n) {
        // base Case
       vector<int> dp(n+1,-1);
       //int ans = bottomUpFib(n);
       int ans = topDownFib(dp,n);

       return ans;
    }
};
