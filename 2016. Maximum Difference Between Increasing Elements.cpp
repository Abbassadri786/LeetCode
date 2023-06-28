class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mini = nums[0];
        int maxi = -1;

        for(int i=0; i < nums.size(); i++){
            mini = min(nums[i], mini);
            if(mini < nums[i]){
            maxi = max(maxi, nums[i]-mini);
            }
        }
        return maxi;
    }
};
