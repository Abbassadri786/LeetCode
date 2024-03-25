class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0; // Check if nums is empty

        sort(nums.begin(), nums.end());
        
        int longestStreak = 1;
        int currentStreak = 1;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i-1]){ // Check for unique numbers only
                if(nums[i] - nums[i-1] == 1){
                    // Found consecutive numbers
                    currentStreak++;
                } else {
                    // Reset streak if non-consecutive
                    longestStreak = max(longestStreak, currentStreak);
                    currentStreak = 1; // Reset current streak
                }
            }
        }
        // Compare the last streak after exiting the loop
        longestStreak = max(longestStreak, currentStreak);
        
        return longestStreak;
    }
};
