class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;

        // Count frequencies of each number
        for (int num : arr) {
            freq[num]++;
        }

        // Set for marking used frequencies
        unordered_map<int, bool> usedFrequencies;

        for (auto &p : freq) {
            int count = p.second;
            if (usedFrequencies.count(count)) {
                // If the count has been used, return false
                return false;
            }
            usedFrequencies[count] = true;
        }

        return true;
    }
};
