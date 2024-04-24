// Approach 1: Without taking empty string space

class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        int n = s.length();
        for (int i = 0; i <= n; i++) {
            // Check for end of a word
            if (i == n || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i); // Reverse the current word in-place
                start = i + 1; // Move to the start of the next word
            }
        }
        return s;
    }
};


// Approach 2: Taking temp String and appending at each iteration then reversing each word
class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        string temp = "";
        int n = s.length();

        for(int i=0 ; i<n; i++){
            // If the character is not a space, add it to the temp string
            if(s[i] != ' '){
                temp += s[i];
            }
            // If it's a space or the end of the string, reverse the current word and append it to the result
            if(s[i] == ' ' || i == n-1){
                reverse(temp.begin(), temp.end());
                if(!res.empty()){
                    res += " ";
                }
                res += temp;
                //Reset the Temp for the next word
                temp = "";
            }
        }
        return res;
    }
};
