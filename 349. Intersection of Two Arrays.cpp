class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set(nums1.begin(), nums1.end()); // Create a set from nums1
        vector<int> res;

        for (int num : nums2) {
            // If num is found in the set, add to result and erase from set
            if (set.count(num)) {
                res.push_back(num);
                set.erase(num); // Remove the number to prevent duplicates
            }
        }

        return res; 
    }
};
