class Solution {
public:
void sol(int k,string &s){
    if(s.size()>=k){
        return;
    }
    int n=s.size();
    for(int i=0;i<n;i++){
      s += (char)(((s[i] - 'a' + 1) % 26) + 'a');
    }
    sol(k,s);
}
    char kthCharacter(int k) {  
        string s="a";
      sol(k,s); 
      return s[k-1]; 
    }
};
