// count no. of subarrays where sum <= goal but actually we are looking for no. of subarrays sum == goal
// so by Func(nums, goal) - Function(nums, goal - 1) will give us output

class Solution {
private:
    int subArrays(vector<int>& nums, int goal){
        
        // Edge case: no subarray can have negative sum in binary array
        if(goal < 0) return 0;

        int n = nums.size();
        int l = 0, r = 0;
        int cnt = 0, sum = 0;

        while(r < n){
            // Expand window by including nums[r]
            sum += nums[r];

            // Shrink window if sum exceeds goal
            while(sum > goal){
                sum -= nums[l];
                l++;
            }

            // All subarrays ending at r with start from l to r are valid
            cnt += (r - l + 1);
            r++;
        }

        return cnt;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Exactly goal = atMost(goal) - atMost(goal-1)
        return subArrays(nums, goal) - subArrays(nums, goal - 1);
    }
};
