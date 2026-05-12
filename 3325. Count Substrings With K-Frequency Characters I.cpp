class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        // Using Sliding window technique
        int n = s.length();

        vector<int> freq(26, 0);

        int l = 0;
        int ans = 0;

        for(int r = 0; r < n; r++) {

            // Expand window
            freq[s[r] - 'a']++;

            // Shrink while window is valid
            while(freq[s[r] - 'a'] >= k) {

                // All substrings from r to end are valid
                ans += (n - r);

                // Contract window
                freq[s[l] - 'a']--;
                l++;
            }
        }

        return ans;
    }
};
