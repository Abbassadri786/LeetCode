class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0, r = 0, maxLen = 0;
        unordered_map<int, int> mp;

        while (r < n) {
            // Add current fruit to basket
            mp[fruits[r]]++;

            // Shrink window if more than 2 fruit types
            while (mp.size() > 2) {
                mp[fruits[l]]--;     /// reduce freq of that elem in map
                if (mp[fruits[l]] == 0) {
                    mp.erase(fruits[l]); // erase by key
                }
                l++;
            }

            // Update maximum length of valid window
            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};
