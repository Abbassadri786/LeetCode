class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        int totalLength = len1 + len2;
        string res;
        res.reserve(totalLength); // Pre-allocate memory to avoid reallocations
        
        int i = 0, j = 0;
        // Use a single loop to merge characters alternately until one string ends
        while (i < len1 && j < len2) {
            res += word1[i++];
            res += word2[j++];
        }
        
        // Append the remainder of the longer string directly
        // No need for two separate while loops
        if (i < len1) {
            res += word1.substr(i);
        } else if (j < len2) {
            res += word2.substr(j);
        }

        return res;
    }
};
