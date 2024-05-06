class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0, cnt_even = 0;
        for(int i=0; i<nums.size(); i++){
            int curr = nums[i];
            cnt = 0;
            while(curr > 0){
                curr /= 10;
                cnt++;
            }
            if(cnt % 2 ==0){
                cnt_even++;
            }
        }
        return cnt_even;
    }
};
