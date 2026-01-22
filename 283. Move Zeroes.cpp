//Approach 1: two-pointer approach (i and k) to push zeros to the end while keeping order of non-zero elements.
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k= 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0){
                if(i != k) swap(nums[i], nums[k]);
                k++;
            }
        }
    }
};
//Approach 2: Also 2 pointer but unnecessary swaps
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()==1) return;
        int left = 0;
        int right = 0;
        while(right < nums.size()){
            // If condition == 0 then zeroes will get in front
            // If condition != 0 then zeroes will go at back
            if(nums[right] != 0){
                swap(nums[left], nums[right]);
                left++;
            }
            
            right++;
        }
        
    }
};
