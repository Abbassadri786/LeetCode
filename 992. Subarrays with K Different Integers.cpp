// Approach : Using Sliding window atMost(k) - atMost(k-1)
class Solution {
private:
    int subArrays(vector<int>& nums, int k){
        if(k < 0) return 0;

        int n = nums.size();
        int l = 0, r = 0, cnt = 0;
        unordered_map<int, int> mp;

        while(r < n){
            // Expand window
            mp[nums[r]]++;

            // Shrink window only when invalid (distinct > k)
            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0){
                    mp.erase(nums[l]);
                }
                l++;
            }

            // Count subarrays ending at r with at most k distinct
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subArrays(nums, k) - subArrays(nums, k - 1);
    }
};
