class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while(low <= high){
            int mid = (high + low) / 2;
            if(nums[mid] == target) return mid;
            // search in left sorted array
            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            // search in right sorted array
            else{
                if(nums[high] >= nums[mid]){
                    if(nums[high] >= target && target >= nums[mid]){
                        low = mid + 1;
                    }
                    else{
                        high = mid -1;
                    }
                }
            }
        }
        return -1;
        
    }
};
