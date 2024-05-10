class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        map<int, int> events;
        for (const auto& interval : nums) {
            events[interval[0]]++;          // Start covering
            events[interval[1] + 1]--;      // Stop covering
        }

        int totalPoints = 0;
        int activeIntervals = 0;
        int prevPoint = -1;

        for (const auto& event : events) {
            if (activeIntervals > 0) {
                totalPoints += event.first - prevPoint;
            }
            activeIntervals += event.second;
            prevPoint = event.first;
        }

        return totalPoints;
    }
};
