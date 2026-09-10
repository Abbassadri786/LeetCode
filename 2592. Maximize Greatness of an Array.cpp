class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int idx = 0;

        for(int elm: nums){
            if(elm > nums[idx]){
                idx++;
            }
        }

        return idx;
    }
};
