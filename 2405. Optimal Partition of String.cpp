class Solution {
public:
    int partitionString(string s) {
        // so my approach
        // inittialize map/set to keep tract of each char's ooccur
        // iterate whole string
        //if found any repeated char then increase count and start observing next char and repeat the same untill whole string is not traveresed
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
