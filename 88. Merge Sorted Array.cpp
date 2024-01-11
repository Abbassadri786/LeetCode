class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int size = m + n;
        int itr1 = m - 1, itr2 = n - 1;
        int mergedIndex = size - 1;

        while (itr1 >= 0 && itr2 >= 0) {
            if (nums1[itr1] >= nums2[itr2]) {
                nums1[mergedIndex--] = nums1[itr1];
                itr1--;
            } else {
                nums1[mergedIndex--] = nums2[itr2];
                itr2--;
            }
        }

        // If there are remaining elements in nums2
        while (itr2 >= 0) {
            nums1[mergedIndex] = nums2[itr2];
            itr2--;
            mergedIndex--;
        }        
    }
};
