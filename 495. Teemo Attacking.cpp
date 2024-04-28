class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0; 

        int totalDuration = 0;

        for (int i = 0; i < timeSeries.size() - 1; ++i) {
            // Calculate the difference between the current attack time and the next attack time
            int diff = timeSeries[i + 1] - timeSeries[i];
            // If the difference is less than the duration, Ashe's poison duration extends only till the next attack
            // Otherwise, the poison lasts for its full duration
            if (diff < duration) {
                totalDuration += diff;
            } else {
                totalDuration += duration;
            }
        }
        // For the last one the time for poisend will always be = duration
        totalDuration += duration;

        return totalDuration;
    }
};
