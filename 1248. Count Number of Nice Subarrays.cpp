class Solution {
private:
    int subArrays(vector<int>& nums, int k){
        // Edge case: no subarray can have negative odd count
        if(k < 0) return 0;

        int n = nums.size();
        int l = 0, r = 0;
        int odds = 0, cnt = 0;

        while(r < n){
            // Expand window: add current element's odd contribution
            odds += nums[r] % 2;

            // Shrink window if odd count exceeds k
            while(odds > k){
                odds -= nums[l] % 2;
                l++;
            }

            // All subarrays ending at r with start from l to r are valid
            cnt += (r - l + 1);
            r++;
        }

        return cnt;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // Exactly k odds = atMost(k) - atMost(k-1)
        return subArrays(nums, k) - subArrays(nums, k - 1);
    }
};
