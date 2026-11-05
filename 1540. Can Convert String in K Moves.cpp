class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        
        if(s.size() != t.size()) return false;

        vector<int>freq(26,0);
        //you can perform only one operation per move

        for(int i = 0; i < s.size(); i++){
            int diff = (t[i] - s[i] + 26) % 26;
            if(diff == 0) continue;
            
            //freq[diff] helps us remember how many times we've already used that particular shift, while multiplying it by 26 gives us the next available move number.
            int operations = diff + 26 * freq[diff];
            
            if(operations > k) return false;

            freq[diff]++;
        }

        return true;
    }
};
