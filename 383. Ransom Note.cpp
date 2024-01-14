class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int counter[26] = {0};
        //Checking the characters in Magazine sring
        for(char c : magazine){
            counter[c - 'a']++;
        }
        // Now verifying the magazine string characters in ransomNote
        for(char c : ransomNote){
            if(counter[c-'a']-- <= 0){
                return false;
            }
        }
        return true;
    }
};
