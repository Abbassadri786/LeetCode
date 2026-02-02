//Approach 1: Brute force sol using recurrsion, so optimize this using dp by reducing no. of iterations
class Solution {
  private:
    bool solve(int idx, string &s, vector<string> &wordDict) {
        // base case
        if(idx == s.length()) {
            return true;
        }

        // try all substrings starting from idx
        for(int i = idx; i < s.length(); i++) {
            string left = s.substr(idx, i - idx + 1);

            // check if left exists in dictionary
            for(string &word : wordDict) {
                if(word == left) {
                    if(solve(i + 1, s, wordDict))
                        return true;
                }
            }
        }
        return false;
    }

  public:
    bool wordBreak(string &s, vector<string> &wordDict) {
        return solve(0, s, wordDict);
    }
};

//Approach 2: Memoization 
class Solution {
  private:
    bool solve(int idx, string &s, vector<string> &dictionary, vector<int> &dp) {

        // base case
        if(idx == s.length()) return true;

        // memo check
        if(dp[idx] != -1) return dp[idx];

        // try all substrings starting from idx
        for(int i = idx; i < s.length(); i++) {
            string left = s.substr(idx, i - idx + 1);

            for(string &word : dictionary) {
                if(word == left) {
                    if(solve(i + 1, s, dictionary, dp))
                        return dp[idx] = true;
                }
            }
        }

        return dp[idx] = false;
    }

  public:
    bool wordBreak(string &s, vector<string> &dictionary) {
        vector<int> dp(s.length(), -1);
        return solve(0, s, dictionary, dp);
    }
};

