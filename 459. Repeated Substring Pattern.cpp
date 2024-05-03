class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for (int len = 1; len <= n / 2; ++len) {
            if (n % len == 0) {  // Only consider lengths that evenly divide n
                string pattern = s.substr(0, len);
                bool match = true;
                for (int i = len; i < n; i += len) {
                    if (s.substr(i, len) != pattern) {
                        match = false;
                        break;
                    }
                }
                if (match) return true;
            }
        }
        return false;
    }
};
