class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
       int n = nums.size();
        int start_idx = -1;
        int end_idx = -2;
        int max_num = nums[0];
        int min_num = nums[n - 1];
        
        // Find the start_idx and end_idx of the unsorted subarray
        for (int i = 1; i < n; i++) {
            max_num = max(max_num, nums[i]);
            min_num = min(min_num, nums[n - 1 - i]);

            if (nums[i] < max_num)
                end_idx = i;
            
            if (nums[n - 1 - i] > min_num)
                start_idx = n - 1 - i;
        }
        
        // If the array is already sorted, return 0
        if (start_idx == -1 && end_idx == -2)
            return 0;

        // Return the length of the shortest unsorted subarray
        return end_idx - start_idx + 1;
    }
};
