class Solution {
public:
    int findPermutationDifference(string s, string t) {
        // To map the character with its position in array
        unordered_map<char, int> mp;
        int n = s.length();
        int sum = 0;

        // First, mapping all the characters and their indices in 't'
        for (int i = 0; i < n; i++) {
            mp[t[i]] = i;
        }

        // Now, finding the character's index in 's' and calculating the difference sum
        for (int i = 0; i < n; i++) {
            if (mp.find(s[i]) != mp.end()) {
                sum += abs(mp[s[i]] - i);
            }
        }

        return sum;
    }
};
