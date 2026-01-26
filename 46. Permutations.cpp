class Solution {
private:
    void permutations(vector<int>& tmp, vector<bool>& visited,
                      vector<vector<int>>& ans, vector<int>& nums) {

        // Base case: one full permutation formed
        if(tmp.size() == nums.size()){
            ans.push_back(tmp);
            return;
        }

        // Try placing each unused number at current position
        for(int i = 0; i < nums.size(); i++){

            // Skip numbers already used in current permutation
            if(!visited[i]){

                // Choose the number
                tmp.push_back(nums[i]);
                visited[i] = true;

                // Recurse to fill the next position
                permutations(tmp, visited, ans, nums);

                // Backtrack: undo the choice
                tmp.pop_back();
                visited[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> tmp;

        // Keeps track of which elements are already used
        vector<bool> visited(n, false);

        permutations(tmp, visited, ans, nums);
        return ans;
    }
};



//Approach 2: w/o using extra space, swapping of elements
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
