class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int max_Consecutive = 0;
        int maxi = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1] == 1){
               max_Consecutive++; 
            }
            else{
                if(nums[i-1] == 1){
                    maxi = max(maxi, max_Consecutive+1);
                }
                max_Consecutive = 0;
            }
        }
        if(nums.back() == 1){
            maxi = max(maxi, max_Consecutive+1);
        }
            return maxi;
    }
};
