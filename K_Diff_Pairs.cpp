class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = i+1;
        int diff=0,cnt = 0;
        set<pair<int,int>>ans;
        while(j < nums.size()){
            diff = abs(nums[i] - nums[j]);
            if(diff == k){
                ans.insert({nums[i],nums[j]});
                i++,j++;
            }
            else if(diff > k){
                i++;    
            }
            else{
                j++;
            }
            if(i==j){
                j++;
            }
        }
        return ans.size();
        
    }
};
