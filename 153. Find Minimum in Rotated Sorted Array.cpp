class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int mini = INT_MAX;

        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[low] <= nums[high]){
                mini = min(nums[low], mini);
                return mini;
            }
            // if left half sorted then pick min and now go on searching on right half so low = mid + 1
            if(nums[low] <= nums[mid]){
                mini = min(mini, nums[low]);
                low = mid + 1;
            }
            // if right half is sorted then pick min and now go on searching on left side
            else{
                mini= min(nums[mid], mini);
                high = mid -1;
            }
        }

        return mini;
        
    }
};
