class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;
        
        while(i < n) {
            
            int j = i;
            int lineLength = 0; // total length of words (no spaces yet)
            
            // Step 1: pick words that fit in current line
            while(j < n && lineLength + words[j].size() + (j - i) <= maxWidth) {
                lineLength += words[j].size();
                j++;
            }
            
            int numWords = j - i;
            int totalSpaces = maxWidth - lineLength;
            
            string line = "";
            
            // Step 2: if last line OR only one word → left justify
            if(j == n || numWords == 1) {
                
                for(int k = i; k < j; k++) {
                    line += words[k];
                    if(k < j - 1) line += " "; // single space
                }
                
                // fill remaining spaces at end
                while(line.size() < maxWidth) {
                    line += " ";
                }
            }
            else {
                // Step 3: fully justify
                
                int spacesBetween = totalSpaces / (numWords - 1); // base spaces
                int extraSpaces = totalSpaces % (numWords - 1);   // extra spaces
                
                for(int k = i; k < j; k++) {
                    line += words[k];
                    
                    if(k < j - 1) {
                        // add base spaces
                        int spaces = spacesBetween;
                        
                        // distribute extra spaces to left slots first
                        if(extraSpaces > 0) {
                            spaces++;
                            extraSpaces--;
                        }
                        
                        line += string(spaces, ' ');
                    }
                }
            }
            
            result.push_back(line);
            i = j; // move to next set of words
        }
        
        return result;
    }
};
