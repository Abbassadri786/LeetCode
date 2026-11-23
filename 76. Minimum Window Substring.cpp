// Approach: Sliding Window(variable) technique

class Solution {
public:
    string minWindow(string s, string t) {
        int k = t.size();
        int n = s.size();

        if(k > n) return "";

        // Store the required frequency of each character in t
        unordered_map<char, int> freq;
        for(int i = 0; i < k; i++) {
            freq[t[i]]++;
        }

        int i = 0, j = 0, start_i = 0;
        int reqChar = k;  // Total characters still needed (including duplicates)
        int mini = INT_MAX;

        while(j < n) {

            // Expand window: count a character only if it's still needed
            if(freq[s[j]] > 0) {
                reqChar--;
            }

            // Decrease frequency (negative means extra occurrences)
            freq[s[j]]--;

            // All characters of t are present in the current window
            while(reqChar == 0) {

                // Update the minimum window length and starting index
                if(mini > j - i + 1) {
                    mini = j - i + 1;
                    start_i = i;
                }
                // Shrink window from the left
                freq[s[i]]++;

                // If a required character is removed, window becomes invalid
                if(freq[s[i]] > 0) {
                    reqChar++;
                }
                i++;
            }
            j++;
        }

        return mini == INT_MAX ? "" : s.substr(start_i, mini);
    }
};
