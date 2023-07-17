class Solution {
public:
static bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if (a.second == b.second) {
        return a.first > b.first;
    }
    return a.second < b.second;
}

vector<int> frequencySort(vector<int>& nums) {
    unordered_map<int, int> freqMap;
    vector<pair<int, int>> freqPairs;

    for (int num : nums) {
        freqMap[num]++;
    }

    for (auto it : freqMap) {
        freqPairs.push_back({ it.first, it.second });
    }

    sort(freqPairs.begin(), freqPairs.end(), cmp);

    vector<int> result;
    for (auto& pair : freqPairs) {
        int num = pair.first;
        int freq = pair.second;
        for (int i = 0; i < freq; ++i) {
            result.push_back(num);
        }
    }
    return result;
    }
};
