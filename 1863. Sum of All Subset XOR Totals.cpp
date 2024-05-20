class Solution {
public:
// By the Backtracking approach to choose Subset
    void calculateXORSum(vector<int>& nums, int index, int currentXOR, int& sum) {
        if (index == nums.size()) {
            sum += currentXOR;
            return;
        }
        
        // Include nums[index] in the current subset
        calculateXORSum(nums, index + 1, currentXOR ^ nums[index], sum);
        
        // Exclude nums[index] from the current subset
        calculateXORSum(nums, index + 1, currentXOR, sum);
    }
    
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        calculateXORSum(nums, 0, 0, sum);
        return sum;
    }
};
