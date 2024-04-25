class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string filtered = "";
        for (char c : s) {
            if (c != '-') {
                filtered += toupper(c);
            }
        }
        
        int n = filtered.length();
        int firstGroup = n % k;
        string ans = "";
        
        if (firstGroup == 0 && n > 0) firstGroup = k;
        int itr = 0;
        for (int i = 0; i < firstGroup; ++i) {
            ans += filtered[i];
            itr++;
        }
        
        for (int i = itr; i < n; i++) {
            if ((i - firstGroup) % k == 0 && i > 0) {
                ans += "-";
            }
            ans += filtered[i];
        }      
        return ans;
    }
};
