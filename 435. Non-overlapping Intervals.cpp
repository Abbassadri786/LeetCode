// Approach: using Greedy Algorithm Keep intervals that finish early, they leave more room for others.

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // Sort intervals by their ending time
        // Greedy choice: always pick the interval that ends earliest
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
                 return a[1] < b[1];
        });

        // Keep the first interval
        int lastEndTime = intervals[0][1];
        int cnt = 1;  // number of non-overlapping intervals kept

        // Traverse remaining intervals
        for(int i = 1; i < n; i++) {
            // If current interval starts after or when last one ends
            if(intervals[i][0] >= lastEndTime) {
                cnt++;  // keep this interval
                lastEndTime = intervals[i][1];
            }
            // else: overlap → skip (remove) this interval
        }

        // intervals to remove = total - kept
        return n - cnt;
    }
};
