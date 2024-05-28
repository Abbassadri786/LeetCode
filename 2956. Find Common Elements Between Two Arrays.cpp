class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int ans1 = 0;
        unordered_set<int> set1(nums2.begin(),nums2.end());

        for(auto itr: nums1){
            if(set1.find(itr) != set1.end()){
                ans1++;
            }
        }

        int ans2 = 0;
        unordered_set<int> set2(nums1.begin(),nums1.end());

        for(auto itr: nums2){
            if(set2.find(itr) != set2.end()){
                ans2++;
            }
        }

        return {ans1,ans2};
    }
};
