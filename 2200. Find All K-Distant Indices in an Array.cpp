class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {

        int n = nums.size();
        vector<int> ans;

        // Check every index in the array
        for(int i = 0; i < n; i++) {

            bool valid = false;

            // Search within k distance from current index
            for(int j = max(0, i - k);
                j <= min(n - 1, i + k);
                j++) {

                // Found a key element within range
                if(nums[j] == key) {
                    valid = true;
                    break;
                }
            }

            // Current index is k-distant from at least one key index
            if(valid) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

// Solved twice
