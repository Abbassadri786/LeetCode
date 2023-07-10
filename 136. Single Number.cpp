class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x_or = 0;
        for(int i=0; i<nums.size(); i++){
            x_or ^= nums[i];
        }

        return x_or;
    }
};
