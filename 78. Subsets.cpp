class Solution {
private:
    void subsets(int idx, vector<vector<int>>& ans, vector<int>& tmp, vector<int>& nums){

        //Add the current tmp to ans at every recursive call, not only at the base case.
        ans.push_back(tmp); 

        for(int i=idx; i<nums.size(); i++){
            tmp.push_back(nums[i]);
            subsets(i+1,ans,tmp, nums);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>tmp;
        subsets(0,ans,tmp, nums);

        return ans;
        
    }
};
