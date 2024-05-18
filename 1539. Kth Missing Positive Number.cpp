class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int missingCount = 0;
        int lastChecked = 0;

        for (int num : arr) {
            // Count the missing numbers between lastChecked + 1 and num - 1
            while (lastChecked + 1 < num) {
                missingCount++;
                lastChecked++;
                if (missingCount == k) {
                    return lastChecked;
                }
            }
            lastChecked = num;
        }

        
        return lastChecked + (k - missingCount);
    }
};
