class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // Frequencies of the characters b, a, l, o, and n
        int b = 0, a = 0, l = 0, o = 0, n = 0;
        
        // Count the frequency of each character in the input string
        for (char c : text) {
            switch (c) {
                case 'b': ++b; break;
                case 'a': ++a; break;
                case 'l': ++l; break;
                case 'o': ++o; break;
                case 'n': ++n; break;
            }
        }
        
        // Since 'l' and 'o' are needed twice in "balloon", divide their counts by 2
        l /= 2;
        o /= 2;
        
        // The maximum number of "balloon"s that can be formed
        // is determined by the minimum frequency of the required characters
        return min({b, a, l, o, n});
    }
};
