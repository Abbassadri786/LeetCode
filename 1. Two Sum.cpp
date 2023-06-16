class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ansMap;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            int complement = target - nums[i];
          // Find Complement in the array
            if(ansMap.count(complement)){
                return {ansMap[complement], i};
            }
          // Updating the map with new values
            ansMap[nums[i]] = i;
        }
        // If no Solution found
        return {};
        
    }
};
