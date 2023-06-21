// APPROACH 1 USING SET
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    set<int> s; 
        for(int i =0; i<nums.size(); i++)
        {
            s.insert(nums[i]);
        }
        
        int ans = s.size();
        nums.clear();
        for(auto i:s)
        {
           //int k = *i;
           nums.push_back(i);
        }
        return ans;
    }
};

// APPROACH 2 USING VARIABLE J TO COMPARE WITH CURR
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0, n = nums.size();
        if(n == 0 || n == 1){
            return n;
        }
        
        for(int i = 0; i < n-1; i++){
            if(nums[i] != nums[i+1]){
                nums[j++] = nums[i];
            }
        }
      // Handle the Last element also a case if there is only 1 kind of repeated element in the array 
        nums[j++] = nums[n-1];
        return j;
        
    }
};
