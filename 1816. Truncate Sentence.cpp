class Solution {
public:
    string truncateSentence(string s, int k) {
        int n = s.length();
        int spaceCount = 0;
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') {
                ++spaceCount;
                if (spaceCount == k) {
                    return s.substr(0, i);
                }
            }
        }
        
        return s;
    }
};
