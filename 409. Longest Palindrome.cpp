class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char ,int> freq;
        int length = 0;
        bool hasOdd = false;
        for(char itr: s){
            freq[itr]++;
        }

        for(auto& p: freq){
            // Even waala case toh hamesha add hoga kyoki wo hamesha palindrome he
            if(p.second %2 == 0){
                length += p.second;
            }
            else{
                // Odd freq type ko Even format me convert
                length += p.second - 1;
                hasOdd = true;
            }
        }

        if(hasOdd){
            length += 1;
        }
        return length;
        
    }
};
