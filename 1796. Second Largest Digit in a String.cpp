class Solution {
public:
    int secondHighest(string s) {
        
        int first_max = -1;
        int second_max = -1;

        // Traverse entire string
        for(int i = 0; i < s.length(); i++) {
            
            // Check if current character is a digit
            if(s[i] >= '0' && s[i] <= '9') {
                
                int digit = s[i] - '0';

                // Update largest digit
                if(digit > first_max) {
                    second_max = first_max;
                    first_max = digit;
                }

                // Make sure digit is different from first_max
                else if(digit > second_max && digit != first_max) {
                    second_max = digit;
                }
            }
        }

        return second_max;
    }
};
