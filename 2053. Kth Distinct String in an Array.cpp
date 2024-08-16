class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> freq;
        
        // Build frequency map
        for (const string& s : arr) {
            freq[s]++;
        }

        // Find k-th distinct string
        for (const string& s : arr) {
            if (freq[s] == 1) {
                k--;
                if (k == 0) {
                    return s;
                }
            }
        }
        
        return "";
    }
};
