class Solution {
private:
    // Helper function to expand around center and count palindromes
    void help(string &s, int start, int end, int &cnt){
        
        // Expand while within bounds and characters match
        while(start >= 0 && end < s.size() && s[start] == s[end]){
            
            // Found a valid palindrome 
            cnt++;

            // Expand outward
            start--;
            end++;
        }
    }

public:
    int countSubstrings(string s) {

        // Edge case: empty string
        if(s.length() == 0) return 0;

        int cnt = 0;

        // Try every index as center
        for(int i = 0; i < s.length(); i++){

            // Case 1: Odd length palindrome (center at i)
            help(s, i, i, cnt);

            // Case 2: Even length palindrome (center between i and i+1)
            help(s, i, i+1, cnt);
        }

        return cnt;
    }
};
