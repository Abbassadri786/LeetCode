class Solution {
private:
    int lowerB(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0, high = n-1;
        int ans = n;

        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] >= target){
                high = mid - 1;
                ans = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    int upperB(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0, high = n-1;
        int ans = n;

        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] > target){
                high = mid - 1;
                ans = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lowerB(nums, target);

        if(lb == n || nums[lb] != target) return {-1, -1};

        return {lb, upperB(nums, target) - 1};
    }
};
