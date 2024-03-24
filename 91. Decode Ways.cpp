class Solution {
public:
    int numDecodings(string s) {
        // Create a memoization table, initialized with -1, indicating that no calculation has been done yet
        vector<int> memo(s.length(), -1);
        return decode(0, s, memo);
    }
    
private:
    int decode(int index, const string& s, vector<int>& memo) {
        // If we reach the end of the string, return 1 to count as a valid decoding
        if (index == s.length()) return 1;
        
        // If the string starts with '0', it cannot be decoded
        if (s[index] == '0') return 0;
        
        // If we have already calculated this subproblem, return the result from the memo table
        if (memo[index] != -1) return memo[index];
        
        // Decode a single character
        int result = decode(index + 1, s, memo);
        
        // If the next character also makes a valid number (10 to 26),
        // decode the next two characters
        if (index + 1 < s.length() && (s[index] == '1' || (s[index] == '2' && s[index + 1] < '7'))) {
            result += decode(index + 2, s, memo);
        }
        
        // Store the result in memo table before returning
        memo[index] = result;
        
        return result;
    }
};
