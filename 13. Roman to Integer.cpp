class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {
            {'I' , 1},
            {'V' , 5},
            {'X' , 10},
            {'L' , 50},
            {'C' , 100},
            {'D' , 500},
            {'M' , 1000}
        };

        int num = 0;
        for(int i = 0; i < s.length(); i++) {
            if(i + 1 < s.length() && mp[s[i]] < mp[s[i + 1]]) {
                num += mp[s[i + 1]] - mp[s[i]];
                i++; // Skip the next character
            } else {
                num += mp[s[i]];
            }
        }
        return num;
    }
};
