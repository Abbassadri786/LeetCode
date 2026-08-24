class Solution {
public:
    int partitionString(string s) {
        int n = s.length();
        int cnt = 1; //Because the first partition starts as soon as the string has characters.
        unordered_map<char, int> mp;

        for(int i = 0; i < n; i++) {

            // If this character already exists in the current partition
            if(mp.find(s[i]) != mp.end()) {
                cnt++;

                // Start a new partition
                mp.clear();
            }

            // Add current character to the current partition
            mp[s[i]]++;
        }

        return cnt;
    }
};
