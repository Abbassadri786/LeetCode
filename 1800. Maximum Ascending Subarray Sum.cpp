class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
      // Initialize sum and maxi with first element of array to cover single maximum element case
        int sum = nums[0];
        int maxi = sum;

      // Start from 1 to n as its easy to compare and evaluate
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]){
                sum += nums[i];
                
            }
            else{
                sum = nums[i];
            }
            maxi = max(sum,maxi);  
        }
        return maxi;
        
    }
};
