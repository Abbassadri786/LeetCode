class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int mini = INT_MAX;

        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[low] <= nums[high]){
                mini = min(nums[low], mini);
                break;
            }
            // search if min exist in left
            if(nums[low] <= nums[mid]){
                mini = min(mini, nums[low]);
                low = mid + 1;
            }
            // search if min exists in right
            else{
                mini= min(nums[mid], mini);
                high = mid -1;
            }
        }

        return mini;
        
    }
};
