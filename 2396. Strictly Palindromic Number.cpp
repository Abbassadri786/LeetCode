class Solution {
public:
    bool palindromeCheck(string s){
        int n = s.length();
        int l = 0;
        int h = n - 1;

        while(l < h){
            if(s[l] != s[h]){
                return false;
            }
            l++,h--;
        }
        return true;
    }
    bool isStrictlyPalindromic(int n) {
        string temp;
        
        for(int i = 2; i  <= n-2; i++){
            int org = n;
            temp = "";
            while(org != 0){
                int rem = org % i;
                org /= i;
                temp += to_string(rem);
            }
            if(!palindromeCheck(temp)){
                return false;
            }
        }
        return true;
    }
};
