class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0; // To count the number of places where the array is not non-decreasing
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) { // Use modulo to wrap around to the start of the array
                count++;
            }
            if (count > 1) { // If there are more than one violations, it's not sorted and rotated
                return false;
            }
        }
        // The array is sorted and rotated if we have 0 or 1 violations
        return true;
    }
};
