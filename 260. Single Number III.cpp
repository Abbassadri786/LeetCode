class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
        unordered_map<int,int> mp;
        for(int itr : nums){
            mp[itr]++;
        }
        for(int itr : nums){
            if(mp[itr] == 1){
                res.push_back(itr);
            }
        }

        return res;
    }
};
