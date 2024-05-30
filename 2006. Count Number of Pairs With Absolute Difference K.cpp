class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int cnt = 0;
        unordered_map<int, int> freq;

        for (int num : nums) {
            // Count pairs with the absolute difference k
            // num - k for if and num + k for covering both type of pairs with abs()  
            cnt += freq[num - k] + freq[num + k];
            
            freq[num]++;
        }

        return cnt;
    }
};
