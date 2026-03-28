class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;

        // Step 1: sort array for two-pointer + duplicate handling
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i = 0; i < n; i++){

            // Skip duplicate 'i' elements to avoid duplicate triplets
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int j = i + 1;      // left pointer
            int k = n - 1;      // right pointer

            while(j < k){

                int sum = nums[i] + nums[j] + nums[k];

                if(sum > 0){
                    // Need smaller sum → move right pointer left
                    k--;
                }
                else if(sum < 0){
                    // Need larger sum → move left pointer right
                    j++;
                }
                else{
                    // Found valid triplet
                    ans.push_back({nums[i], nums[j], nums[k]});

                    j++;
                    k--;

                    // Skip duplicate j values
                    while(j < k && nums[j] == nums[j-1]) j++;

                    // Skip duplicate k values
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
            }
        }

        return ans;
    }
};
