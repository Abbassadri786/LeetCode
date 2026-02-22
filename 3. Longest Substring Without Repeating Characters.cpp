// Approach 2: Optimized using hashmap and left right pointer
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l = 0, r = 0, maxLen = 0;
        unordered_map<char, int> hash;

        while (r < n) {
            // If character seen before AND inside current window
            if (hash.find(s[r]) != hash.end() && hash[s[r]] >= l) {
                l = hash[s[r]] + 1;
            }

            // Update max length of current window
            maxLen = max(maxLen, r - l + 1);

            // Store/update last seen index of current character
            hash[s[r]] = r;
            r++;
        }

        return maxLen;
    }
};
