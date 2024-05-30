class Solution {
public:
    bool isPalindrome(string s){
        int start = 0;
        int end = s.length() - 1;

        while(start <= end){
            if(s[start] != s[end]){
                return false;
            }
            start++,
            end--;
        }

        return true;
    }
    string firstPalindrome(vector<string>& words) {
        int n = words.size();
        for(int i=0; i<n; i++){
            if(isPalindrome(words[i])){
                return words[i];
            }
        }
        return "";
    }
};
