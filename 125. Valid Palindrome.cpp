class Solution {
public:
    string filterString(const string& s) {
        string filteredStr;
        for (char c : s) {
            if (isalnum(c)) {
                filteredStr += tolower(c);
            }
        }
        return filteredStr;
    }

    bool checkPalindrome(const string& s) {
        int l = 0;
        int r = s.length() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        string filteredStr = filterString(s);
        return checkPalindrome(filteredStr);
    }

};
