class Solution {
public:
    bool isPalindrome(string& s, int start, int end){
        while(start <= end){
            if(s[start] != s[end]){
                return false;
            }
            start++, end--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                // Check two possibilities: skipping left or right character
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
            left++;
            right--;
        }
        return true;
    }
};
