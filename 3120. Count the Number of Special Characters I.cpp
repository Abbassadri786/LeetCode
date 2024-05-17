class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        unordered_set<char> check(word.begin(), word.end());
        int cnt = 0;

        for(auto &ch: check){
            if(ch >= 'A' && ch <= 'Z'){
                if(check.find(ch - 'A' + 'a') != check.end()){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
