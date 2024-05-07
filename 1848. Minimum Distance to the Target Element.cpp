class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
       int minDistance = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                int distance = abs(start - i);
                minDistance = min(minDistance, distance);
            }
        }
        return minDistance;
    }
};
