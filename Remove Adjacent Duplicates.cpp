class Solution {
public:
    string removeDuplicates(string s) {
         int nRemoved = 0;
        
        do{
            nRemoved = 0;
            for(int i = 0; i < s.size() - 1;){
                if(s[i] == s[i+1]){
                    //remove from i, length 2
                    // cout << S.size() << ", " << i << endl;
                    s.erase(i, 2);
                    i--;
                    nRemoved++;
                }else{
                    i++;
                }
            }
        }while(nRemoved > 0 && s.size() > 0);
        
        return s;
    }
};
