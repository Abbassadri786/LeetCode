class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> freq;

        for(int itr: nums){
            freq[itr]++;
        }
        int max_sequence = 0;
        for (auto p : freq) {
            if (freq.find(p.first - 1) != freq.end()) {
                max_sequence = max(max_sequence, p.second + freq[p.first - 1]);
            }
        }
        return max_sequence;
    }
};
