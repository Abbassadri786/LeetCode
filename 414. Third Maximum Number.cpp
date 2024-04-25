class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();
        if(n < 3) return nums[0];

        int distinctNum = 1;
        for(int i=1; i<n; i++){
            if(nums[i] != nums[i-1]){
                distinctNum++;
                if(distinctNum == 3){
                    return nums[i];
                }
            }
        }

        return nums[0];
    }
};
