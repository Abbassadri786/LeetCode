class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        int count = 0;

        while (left < right) {
            if (nums[left] + nums[right] < target) {
                count += (right - left); // All pairs from left to right-1 are valid
                left++; // Move the left pointer to the right to find new pairs
            } else {
                right--; // Decrease the right pointer to reduce the sum
            }
        }
        return count;
    }    
};
