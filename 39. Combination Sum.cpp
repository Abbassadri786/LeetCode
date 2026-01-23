// At each index: A) Pick the number (stay at same index → unlimited use)
// B) Skip the number (move to next index)
class Solution {
private:
    void findCombinations(int idx, vector<int>& arr, int target, vector<vector<int>>& ans, vector<int>& tmp){
        if(arr.size() == idx){
            if(target == 0){
                ans.push_back(tmp);
            }
            return;
        }

        if(arr[idx] <= target){
            tmp.push_back(arr[idx]);
            findCombinations(idx, arr, target - arr[idx], ans, tmp);
            tmp.pop_back();
        }
        findCombinations(idx+1, arr, target, ans, tmp);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>tmp;
        findCombinations(0, candidates, target, ans, tmp);
        return ans;
    }
};
