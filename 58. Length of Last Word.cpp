class Solution {
public:
    int lengthOfLastWord(string s) {
        int counter = 0;
        int n = s.length();

        while(n > 0){
            if(s[--n] != ' '){
                counter++;
            }
            else if(counter > 0){
                return counter;
            }
        }

        return counter;
    }
};
