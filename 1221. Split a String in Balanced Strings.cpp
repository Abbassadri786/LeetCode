class Solution {
public:
    int balancedStringSplit(string s) {
        int cnt_R = 0, cnt_L = 0;
        int cnt = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == 'R'){
                cnt_R++;
            }
            else{
                cnt_L++;
            }
            if(cnt_R == cnt_L){
                cnt++;
            }
        }

        return cnt;
    }
};
