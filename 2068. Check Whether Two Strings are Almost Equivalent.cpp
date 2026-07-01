class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
//Since the strings contain only lowercase English letters, we can use arrays
        int freq1[26] = {0};
        int freq2[26] = {0};

        // Count frequencies in word1
        for(char ch : word1) {
            freq1[ch - 'a']++;
        }

        // Count frequencies in word2
        for(char ch : word2) {
            freq2[ch - 'a']++;
        }

        // Compare frequency difference for every character
        for(int i = 0; i < 26; i++) {
            if(abs(freq1[i] - freq2[i]) > 3) {
                return false;
            }
        }

        return true;
    }
};
