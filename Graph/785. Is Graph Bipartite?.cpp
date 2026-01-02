class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);
        queue<int> q;
        // run this loop as graph can be disconnected
        for(int start = 0; start < V; start++){
            if(color[start] != -1) continue;   // already checked component
            
            color[start] = 0;
            q.push(start);

            while(!q.empty()){
                int node = q.front();
                q.pop();

                for(int nbr : graph[node]){
                    if(color[nbr] == -1){
                        color[nbr] = !color[node];
                        q.push(nbr);
                    }
                    else if(color[nbr] == color[node]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
