// Approach 1 using Map
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        
        for(int i = 0; i < nums.size(); i++){
            if(mp.find(nums[i]) != mp.end()){
                if(abs(mp[nums[i]] - i) <= k) return true;
            }
            mp[nums[i]] = i;
        }

        return false;
    }
};
// Approach 2 : using Sliding Window and Unordred Set
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i = 0, j = 0;
        unordered_set<int> st;
        int n = nums.size();

        while(j < n) {

            // Shrink the window if index difference exceeds k
            if(j - i > k) {
                st.erase(nums[i]);
                i++;
            }

            // past me dekha h nums[j]?
            if(st.find(nums[j]) != st.end()) {
                return true;
            }

            // Insert the current element after checking for duplicates
            st.insert(nums[j]);

            j++;
        }

        return false;
    }
};
