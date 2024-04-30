class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;
        int len = s.length();
        for(int i=1; i<len; i++){
            sum += abs(s[i]-s[i-1]);
        }
        return sum;
    }
};
