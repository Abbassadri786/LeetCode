class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        }

        int slow = 2, fast = 2;
    // Slow Fast Pointer Approach
    
        while (fast < n) {
            if (nums[fast] != nums[slow - 2]) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }

        return slow;
      
    }
};
