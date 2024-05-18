class Solution {
public:
    bool isSubstringPresent(string s) {
       int n=s.size();
        for (int i=1; i<n; i++){
            char t[3];
            t[2]='\0';
            t[0]=s[i], t[1]=s[i-1];
            if (s.find(t)!=-1) return 1;
        }
        return 0; 
    }
};
