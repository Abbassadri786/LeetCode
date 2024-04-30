class Solution {
public:
    int countBinarySubstrings(string s) {
     int prevLen = 0, curLen = 1, count = 0;
     
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                curLen++; // Extend the current group
            } else {
                count += min(prevLen, curLen); // Count substrings from the last two groups
                prevLen = curLen; // Previous group is now the current one
                curLen = 1; // Reset length count for new group
            }
        }
        count += min(prevLen, curLen); // Account for the last pair of groups
        return count;   
    }
};
