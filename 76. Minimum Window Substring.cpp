class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length(), m = t.length();
        int l = 0, r = 0;
        int minLen = INT_MAX, sIndex = -1, cnt = 0;

        unordered_map<char, int> hash;

        // Store frequency of characters in t
        for(int i = 0; i < m; i++){
            hash[t[i]]++;
        }

        while(r < n){
            // If current char is needed in window
            if(hash[s[r]] > 0){
                cnt++;
            }
            // Always decrement (important for extra chars tracking)
            hash[s[r]]--;

            // Try to shrink window when all characters are matched
            while(cnt == m){
                // Update minimum window length
                if(r - l + 1 < minLen){
                    minLen = r - l + 1;
                    sIndex = l;
                }

                // Remove left character from window
                hash[s[l]]++;

                // If this character was part of t and now missing
                if(hash[s[l]] > 0){
                    cnt--;
                }

                l++;
            }
            r++;
        }

        return (sIndex == -1) ? "" : s.substr(sIndex, minLen);
    }
};
