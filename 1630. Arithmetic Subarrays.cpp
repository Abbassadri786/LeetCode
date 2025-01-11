class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;

        for(int i=0; i<l.size(); i++){
            int high = r[i];
            int low = l[i];
            
            vector<int> subarray(nums.begin() + low, nums.begin() + high + 1);
            
            sort(subarray.begin(), subarray.end());
            bool isArithmetic = true;
            int diff = subarray[1] - subarray[0];
            for (int j = 1; j < subarray.size(); j++) {
                if (subarray[j] - subarray[j - 1] != diff) {
                    isArithmetic = false;
                    break;
                }
            }
            
            res.push_back(isArithmetic);
        }

        return res;
    }
};
