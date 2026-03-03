// Approach : Using Max Heap Priority Queue 
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // store in pair form => distance(x^2 + y^2), cordinates{x cord, y cord}
        priority_queue<pair<int,pair<int,int>>>pq;
        vector<vector<int>> ans;
        int n = points.size();
        for(int i=0; i<n; i++){
            int x = points[i][0];
            int y = points[i][1];
            int dist = x*x + y*y;
            pq.push({dist,{x,y}});

            if(pq.size() > k){
                pq.pop();
            }
        }

        while(!pq.empty()){
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            vector<int> tmp;
            tmp.push_back(x);
            tmp.push_back(y);
            ans.push_back(tmp);
        }
        return ans;
    }
};
