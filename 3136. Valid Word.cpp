class Solution {
public:
    bool isValid(string word) {
        int len = word.length();
        if(len < 3) return false;
        bool isVowel = false, isConsonant = false;

        for(int i=0; i<len; i++){
            if((word[i] >= '0' && word[i] <= '9') || (word[i] >= 'A' && word[i] <= 'z')){
                if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' || word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U' ){
                    isVowel = true;
                }
                if((word[i] >= 'A' && word[i] <= 'z') && !(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' || word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U')){
                    isConsonant = true;
                }

            }
            else{
                return false;
            }
        }

        return (isVowel && isConsonant);
    }
};
