// Appraoch : 1 Simply iterating whole loop if get greater than next element then return karr jaao
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n-1; i++){
            if(nums[i] > nums[i+1]){
                return i;
            }
        }
        return n-1;
    }
};

// Approach : 2 Using Binary Search with more modifications and writing checking corner cases in advance (Less Efficient Appraoch)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return 0;
        if(nums[0] > nums[1])return 0;
        if(nums[n-1] > nums[n-2])return n-1;
        int start  =  1;
        int end = n-2;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
            {
                return mid;
            }
            else if(nums[mid] > nums[mid-1])
            {
                start = mid + 1;
            }
            else
            {
                end = mid-1;
            }
        }
        return -1;
    }
};
