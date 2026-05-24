class Solution {
public:
    long long countSubstrings(string s, char c) {
        // simple logic 1+2+3......n so n(n+1)/2
        long long cnt = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == c){
                cnt++;
            }
        }
        return cnt*(cnt + 1)/2;
    }
};
