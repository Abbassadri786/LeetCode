// Approach: Sliding Window + Frequency array + max frequency tracking

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int l = 0, r = 0;
        int maxLen = 0;
        int maxF = 0;

        // Frequency array for 26 uppercase letters
        int hash[26] = {0};

        while (r < n) {
            // Add current character to window
            hash[s[r] - 'A']++;

            // Update max frequency in the window
            maxF = max(maxF, hash[s[r] - 'A']);

            // If replacements needed > k, shrink window
            if ((r - l + 1) - maxF > k) {
                hash[s[l] - 'A']--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};
