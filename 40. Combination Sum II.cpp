// At each index: A) Pick the number (stay at same index → unlimited use)
// B) Skip the number (move to next index)
class Solution {
private:
    void findCombinations(int idx, vector<int>& arr, int target, vector<vector<int>>& ans, vector<int>& tmp){

        if(target == 0){
            ans.push_back(tmp);
            return;
        }

        for(int i = idx; i < arr.size(); i++){
            // skip duplicates at same recursion level
            if(i > idx && arr[i] == arr[i - 1]) continue;

            if(arr[i] > target) break;

            tmp.push_back(arr[i]);
            findCombinations(i + 1, arr, target - arr[i], ans, tmp);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // sorting ensures that duplicate candidates are aligned correctly
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int>tmp;
        findCombinations(0, candidates, target, ans, tmp);

        return ans;
    }
};
