class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> people;
        int n= names.size();

        for(int i=0; i<n; i++){
            people.push_back({heights[i],names[i]});
        }
        
        // Sort the vector of pairs
        // We use greater<> to ensure the sort is in descending order based on height
        sort(people.begin(),people.end() ,[](const pair<int,string> &a, const pair<int,string> &b){
            return a.first > b.first;
        });

        vector<string> sorted;
        for(auto &p: people){
            sorted.push_back(p.second);
        }

        return sorted;
    }
};
