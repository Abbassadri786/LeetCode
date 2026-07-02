class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {

        // Store all points for O(1) lookup
        set<pair<int,int>> st;

        for(auto &p : points) {
            st.insert({p[0], p[1]});
        }

        int mini = INT_MAX;
        int n = points.size();

        // Choose any two points
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {

                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                // Must form a diagonal, not same row/column
                if(x1 != x2 && y1 != y2) {

                    // Check whether other two corners exist
                    if(st.count({x1, y2}) &&
                       st.count({x2, y1})) {

                        int area =
                            abs(x1 - x2) *
                            abs(y1 - y2);

                        mini = min(mini, area);
                    }
                }
            }
        }

        return mini == INT_MAX ? 0 : mini;
    }
};
