class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>> pq;
        unordered_map<char ,int> mp;

        string ans = "";
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
        }
        for(auto &itr: mp){
            pq.push({itr.second, itr.first});
        }
        while(!pq.empty()){
            char value = pq.top().second;
            int freq = pq.top().first;
            pq.pop();

            while(freq--){
                ans += value;
            }

        }

        return ans;
    }
};
