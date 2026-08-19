class Solution {
public:
    string modifyString(string s) {
        int n = s.length();
        // approach

        for(int i=0; i<n; i++){

            if(s[i] != '?'){
                continue;
            }
            // Try 'a', 'b', and 'c' and choose one
            // different from both adjacent characters.
            for(char ch ='a';  ch <= 'c'; ch++){
                if((i==0 || s[i-1] != ch) && (i==n-1 || s[i+1] != ch)){
                    s[i] = ch;
                    break;
                }
            }
        }
        return s;
    }
};
