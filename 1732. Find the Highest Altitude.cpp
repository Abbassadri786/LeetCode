class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highestAltitude = 0;
        int currentAltitude = 0;

        for (int g : gain) {
            currentAltitude += g;
            highestAltitude = max(highestAltitude, currentAltitude);
        }

        return highestAltitude;
    }
};
