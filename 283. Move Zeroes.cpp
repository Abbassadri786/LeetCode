class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()==1) return;
        int left = 0;
        int right = 0;
        while(right < nums.size()){
            // If condition == 0 then zeroes will get in front
            // If condition != 0 then zeroes will go at back
            if(nums[right] != 0){
                swap(nums[left], nums[right]);
                left++;
            }
            
            right++;
        }
        
    }
};
