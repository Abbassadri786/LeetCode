class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // Min heap storing {frequency, number}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minH;
        
        unordered_map<int, int> mp;
        
        // Step 1: Count frequencies
        for(int num : nums){
            mp[num]++;
        }
        
        // Step 2: Maintain min heap of size k
        for(auto &p : mp){
            minH.push({p.second, p.first});  // {freq, value}
            
            if(minH.size() > k){
                minH.pop();
            }
        }
        
        // Step 3: Extract elements
        vector<int> ans;
        while(!minH.empty()){
            ans.push_back(minH.top().second);
            minH.pop();
        }
        
        return ans;
    }
};
