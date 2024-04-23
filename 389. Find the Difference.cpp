class Solution {
public:
    char findTheDifference(string s, string t) {
        char result = t[t.size()-1];

        for(int i=0; i < s.size(); i++){
            result ^= s[i];
            result ^= t[i];
        }

        return result;
    }
};
