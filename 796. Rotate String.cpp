class Solution {
public:
    void rotate(string& s, int pos) {
        // First, reverse the entire string
        reverse(s.begin(), s.end());
        // Second, reverse the first part up to the 'pos'
        reverse(s.begin(), s.begin() + pos);
        // Lastly, reverse the second part from 'pos' to the end
        reverse(s.begin() + pos, s.end());
    }

    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        
        // Starting from 1 because rotating by 0 (or the string's length) doesn't change the string
        for (int i = 1; i <= s.length(); i++) {
            if (s == goal) {
                return true;
            }
            rotate(s, 1); // Rotate by one position in each iteration
        }
        return false;
    }
};
