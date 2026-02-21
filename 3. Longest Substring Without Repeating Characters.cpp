class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // If the string is empty -> 0
        if (s.empty()) return 0;

        unordered_set<char> window;
        int left = 0;
        int maxi = 0;

        for (int right = 0; right < (int)s.size(); ++right) {
            char ch = s[right];

            // Move left forward until ch can be inserted (remove duplicates)
            while (window.count(ch)) {
                window.erase(s[left]);
                ++left;
            }

            window.insert(ch);
            maxi = max(maxi, right - left + 1);
        }

        return maxi;
        
    }
};
