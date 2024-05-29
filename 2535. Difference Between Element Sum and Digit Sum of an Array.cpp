class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elemSum = 0;
        int digitSum = 0;

        for(int i=0; i<nums.size(); i++){
            elemSum += nums[i];
            int temp = nums[i];

            while(temp > 0){
                int rem = temp%10;
                digitSum += rem;

                temp /= 10;
            }
        }

        return abs(elemSum - digitSum);
    }
};
