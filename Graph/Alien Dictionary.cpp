class Solution {
  public:
    string findOrder(vector<string> &words) {
        
        vector<vector<int>> adj(26);
        vector<int> present(26, 0);

        // mark present characters
        for(auto &w : words){
            for(char c : w)
                present[c - 'a'] = 1;
        }

        // build graph
        for(int i = 0; i < words.size() - 1; i++){
            string s1 = words[i];
            string s2 = words[i + 1];
            int len = min(s1.size(), s2.size());
            bool diffFound = false;

            for(int ptr = 0; ptr < len; ptr++){
                if(s1[ptr] != s2[ptr]){
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    diffFound = true;
                    break;
                }
            }

            // invalid case: prefix problem
            if(!diffFound && s1.size() > s2.size())
                return "";
        }

        vector<int> indegree(26, 0);
        for(int i = 0; i < 26; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        int totalChars = 0;

        for(int i = 0; i < 26; i++){
            if(present[i]){
                totalChars++;
                if(indegree[i] == 0)
                    q.push(i);
            }
        }

        string ans = "";

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans += char(node + 'a');

            for(auto nbr : adj[node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0)
                    q.push(nbr);
            }
        }

        if(ans.size() == totalChars)
            return ans;

        return "";
    }
};
