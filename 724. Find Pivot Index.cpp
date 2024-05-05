class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;

        for(int itr: nums){
            totalSum += itr;
        }

        int leftSum = 0;

        for(int i = 0; i < nums.size(); i++){
            // Check if Right Sum is equal to Leftsum
            if(leftSum == totalSum - leftSum - nums[i]){
                return i;
            }
            // Maintaining Sum of Left Elements
            leftSum += nums[i];
        }

        return -1;
    }
};
