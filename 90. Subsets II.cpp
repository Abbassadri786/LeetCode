class Solution {
private:
    void subsets(int idx, vector<vector<int>>& ans, vector<int>& tmp, vector<int>& nums){
        ans.push_back(tmp);

        for(int i=idx; i<nums.size(); i++){
             //Avoid duplicates and duplicate elem indices in sorted array
            if(i > idx && nums[i] == nums[i-1]) continue;
            tmp.push_back(nums[i]);
            subsets(i+1,ans, tmp, nums);
            tmp.pop_back();

        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        vector<int>tmp;
        subsets(0,ans, tmp, nums);

        return ans;
        
    }
};
