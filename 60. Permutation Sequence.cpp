// At each step:
// Pick one unused number
// Add it to the current permutation
// Recurse for remaining positions
// Count each full permutation
// Stop when count == k

class Solution {
private:
    void solve(vector<int>& nums, vector<bool>& used,
               string& curr, int& count, int k, string& ans) {

        // If permutation is complete
        if(curr.size() == nums.size()){
            count++;
            if(count == k){
                ans = curr;
            }
            return;
        }

        // Try all unused numbers
        for(int i = 0; i < nums.size(); i++){
            if(used[i]) continue;

            used[i] = true;
            curr.push_back(nums[i] + '0');

            solve(nums, used, curr, count, k, ans);

            // stop early once answer found
            if(!ans.empty()) return;

            curr.pop_back();
            used[i] = false;
        }
    }

public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for(int i = 1; i <= n; i++) nums.push_back(i);

        vector<bool> used(n, false);
        string curr = "";
        string ans = "";
        int count = 0;

        solve(nums, used, curr, count, k, ans);
        return ans;
    }
};
