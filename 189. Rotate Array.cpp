class Solution {
public:
    //APPROACH 1
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n);
        // Taking temp vector to store rotated array
        // Using technique [(i+k) % n]
        for(int i = 0; i < n; i++){
            temp[(i + k) % n] = nums[i];
        }
        
        for(int i = 0; i < n; i++){
            nums[i] = temp[i];
        }
    }
    // APPROACH 2
    void reverse(vector<int>&nums, int low, int high){

        while(low < high){
            swap(nums[low],nums[high]);
            low++,high--;
        }
    }
    void rotate(vector<int>& nums, int k){
        int n = nums.size();
        k = k % n;
        reverse(nums,0, n-k-1);
        reverse(nums,n-k, n-1);
        reverse(nums,0, n-1);  
    }
};
