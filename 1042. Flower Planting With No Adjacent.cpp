class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {

        vector<vector<int>> adj(n + 1);
        for(auto &p : paths){
            int u = p[0];
            int v = p[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> ans(n + 1, 0);

        for(int i=1; i<=n; i++){
            if(ans[i] != 0) continue;

            queue<int> q;
            q.push(i);

            while(!q.empty()){
                int node = q.front();
                q.pop();

                vector<bool> used(5,false);

                for(int nbr: adj[node]){
                    if(ans[nbr] != 0){
                        used[ans[nbr]] = true;
                    }
                }

                for(int flower = 1; flower <=4; flower++){
                    if(!used[flower]){
                        ans[node] = flower;
                        break;
                    }
                }

                for(int nbr: adj[node]){
                    if(ans[nbr] == 0){
                        q.push(nbr);
                    }
                }
            }
        }
        return vector<int>(ans.begin() + 1, ans.end());
    }
};
