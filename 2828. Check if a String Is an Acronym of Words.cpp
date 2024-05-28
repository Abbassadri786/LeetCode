class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        if (words.size() != s.size()) return false;

        for (int i = 0; i < words.size(); ++i) {
            // Compare each character of the acronym string directly with the first character of each word
            if (words[i][0] != s[i]) {
                return false;
            }
        }

        return true;
    }
};
