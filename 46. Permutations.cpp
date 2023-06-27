class Solution {
public:
    void solve(vector<int> nums, vector<vector<int>> &ans, int index){
        if(index >= nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i = index; i < nums.size(); i++){
            swap(nums[index], nums[i]);
            solve(nums, ans, index + 1);

            //Backtracking
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int index = 0;
        vector<vector<int>> ans;
        solve(nums, ans, index);

        return ans;
    }
};
