class Solution {
public:
    int bulbSwitch(int n) {
        if(n==0 || n==1){
            return n;
        }
        int cnt = 0;
        for(int i = 1; i < n; i++){
            int mul = 1;
            mul = i*i;
            if(i*i > n){
                break;
            }
            cnt++;
        }
        return cnt;
        
    }
};
