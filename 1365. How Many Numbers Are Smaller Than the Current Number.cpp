class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
      // Create frequency array with size based on constraints (for 0-100)
        vector<int> freq(101, 0);
        for (int num : nums) {
            freq[num]++;
        }
        
        // Create prefix sum array
        vector<int> counts(101, 0);
        for (int i = 1; i < 101; i++) {
            counts[i] = counts[i - 1] + freq[i - 1];
        }
        
        // Map results back to the input vector size
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = counts[nums[i]];
        }

        return ans;  
    }
};
