class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> freq;
        vector<int> ans;

        for(int itr : nums){
            freq[itr]++;
            if(freq[itr] == 2){
                ans.push_back(itr);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;

    }
};
