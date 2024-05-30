class Solution {
public:
    string maximumOddBinaryNumber(string s) {
       string ans="";
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;i++)if(s[i]=='1')cnt++;
        n-=cnt;
        cnt--;
        while(cnt--)ans+='1';
        while(n--)ans+='0';
        ans+='1';
        return ans; 
    }
};
