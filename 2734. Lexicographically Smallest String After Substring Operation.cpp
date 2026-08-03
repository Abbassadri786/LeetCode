class Solution {
public:
    string smallestString(string s) {
        int n = s.length();
        int i = 0;
      //skip itnitial a's
        while(i<n && s[i]== 'a'){
            i++;
        }
      
      // if end is reached convert last a to z
        if(i == n){
            s[i-1] = 'z';
            return s;
        }
      
      // keep changing chars until next 'a' is found or end is reached
        while(i<n && s[i]!= 'a'){
            s[i]--;
            i++;
        }
        return s;
    }
};
