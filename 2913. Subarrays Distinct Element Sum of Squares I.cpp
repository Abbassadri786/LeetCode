class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();++i)
        {
            unordered_set<int> tmp;
            for(int j=i;j<nums.size();++j)
            {
                tmp.insert(nums[j]);
                ans+=tmp.size()*tmp.size();
            }
        }
        return ans;
    }
};
