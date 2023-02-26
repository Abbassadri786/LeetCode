class Solution {
public:
    bool isPalindrome(int x) {
        
        string num = to_string(x);
        

        int s=0;
        int e = num.size()-1;
        
        while(s<=e){
            if(num[s] != num[e]){
                return false;
            }
            s++,e--;
        }
        return true;
        
    }
};
