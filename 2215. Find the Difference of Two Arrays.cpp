class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        // Prepare two vectors to store unique elements
        vector<int> uniqueInNums1;
        vector<int> uniqueInNums2;

        // Find elements unique to nums1
        for (int num : set1) {
            if (set2.find(num) == set2.end()) {
                uniqueInNums1.push_back(num);
            }
        }

        // Find elements unique to nums2
        for (int num : set2) {
            if (set1.find(num) == set1.end()) {
                uniqueInNums2.push_back(num);
            }
        }

        // Prepare the result vector of vectors
        vector<vector<int>> result = {uniqueInNums1, uniqueInNums2};
        return result;  
    }
};
