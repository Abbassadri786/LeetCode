// Approach: using Sliding window technique of variable k size, shrink when Zeros exceeds k
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int r = 0, l = 0, maxLen = 0, zeros = 0;

        while (r < n) {
            // Expand window
            if (nums[r] == 0) {
                zeros++;
            }

            // Shrink window if zeros exceed k
            while (zeros > k) {
                if (nums[l] == 0) {
                    zeros--;
                }
                l++;
            }

            // Update max window length
            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};
