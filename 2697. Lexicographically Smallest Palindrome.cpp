class Solution {
public:
    string makeSmallestPalindrome(string s) {
         int n = s.length();
        int left = 0, right = n - 1;

        while (left < right) {
            // Make the characters at left and right the same, choosing the lexicographically smaller one
            if (s[left] != s[right]) {
                s[left] = s[right] = min(s[left], s[right]);
            }
            left++;
            right--;
        }

        return s;
    }
};
