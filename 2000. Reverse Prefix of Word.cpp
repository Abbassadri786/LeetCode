class Solution {
public:
    void reverseStr(string &word, int start, int end){
            while(start <= end){
                swap(word[start++], word[end--]);
            }
    }

    string reversePrefix(string word, char ch) {
        for(int i = 0; i < word.length(); i++){
            if(word[i] == ch){
                reverseStr(word,0,i);
                break;
            }
        }

        return word;
    }
};
