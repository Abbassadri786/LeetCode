class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zero = 0, one = 0, two = 0; 
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                zero++;
            }
            else if(nums[i] == 1){
                one++;
            }
            else{
                two++;
            }
        }
        int k = 0;
        for(int i=0; i< zero; i++)nums[k++] = 0;
        for(int i=0; i< one; i++)nums[k++] = 1;
        for(int i=0; i< two; i++)nums[k++] = 2;

        for(int i=0; i<n; i++){
            cout<<nums[i]<<" ";
        }
    }
};
