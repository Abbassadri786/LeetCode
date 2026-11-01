class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Step 1: Build adjacency list
        vector<pair<int,int>> adj[n];
        for(auto it: flights) {
            adj[it[0]].push_back({it[1], it[2]});  // {destination, price}
        }
        
        // Step 2: Initialize distance array and queue
        vector<int> dist(n, 1e9);
        queue<pair<int,pair<int,int>>> q;  // {stops, {node, cost}}
        
        dist[src] = 0;
        q.push({0, {src, 0}});  // Start: 0 stops, at src, cost 0
        
        // Step 3: BFS with stop constraint
        while(!q.empty()) {
            // Step 4: Extract current state
            auto it = q.front();
            q.pop();
            
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            
            // Step 5: Skip if exceeded stop limit
            if(stops > k) continue;
            
            // Step 6: Explore all neighbors
            for(auto iter: adj[node]) {
                int adjNode = iter.first;
                int edW = iter.second;  // Edge weight (price)
                
                // Step 7: Check if we found a cheaper path within stop limit
                if(cost + edW < dist[adjNode] && stops <= k) {
                    // Step 8: Update distance and add to queue
                    dist[adjNode] = cost + edW;
                    q.push({stops + 1, {adjNode, cost + edW}});
                }
            }
        }
        
        // Step 9: Return result
        if(dist[dst] == 1e9) return -1;  // Unreachable within K stops
        return dist[dst];
    }
};
