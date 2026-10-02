class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int n = points.size();
        double ans = DBL_MAX;

        // Store all points for O(1) lookup
        set<pair<int, int>> st;

        for (auto &p : points) {
            st.insert({p[0], p[1]});
        }

        // Pick 3 points
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == i) continue;

                for (int k = j + 1; k < n; k++) {
                    if (k == i) continue;

                    // A = reference point
                    int ax = points[i][0];
                    int ay = points[i][1];

                    int bx = points[j][0];
                    int by = points[j][1];

                    int cx = points[k][0];
                    int cy = points[k][1];

                    // Vectors AB and AC
                    int abx = bx - ax;
                    int aby = by - ay;

                    int acx = cx - ax;
                    int acy = cy - ay;

                    // AB and AC must be perpendicular
                    if (abx * acx + aby * acy != 0)
                        continue;

                    // Fourth point D = B + C - A
                    int dx = bx + cx - ax;
                    int dy = by + cy - ay;

                    // Check whether D exists
                    if (st.find({dx, dy}) == st.end())
                        continue;

                    // Lengths of adjacent sides
                    double side1 = sqrt(1.0 * abx * abx + 1.0 * aby * aby);
                    double side2 = sqrt(1.0 * acx * acx + 1.0 * acy * acy);

                    double area = side1 * side2;

                    ans = min(ans, area);
                }
            }
        }

        return ans == DBL_MAX ? 0 : ans;
    }
};
