class Solution {
public:
    bool isPossibleSol(vector<int>& weights, int days, int sol) {
        int capacity = sol;
        int count = 1;

        for (int weight : weights) {
            if (weight > capacity) {
                count++;
                if (count > days) {
                    return false;
                }
                capacity = sol;
            }
            capacity -= weight;
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        if (n < days) {
            return -1;  // Not enough packages to ship within the given days
        }

        int start = 1;
        int end = 0;

        for (int weight : weights) {
            start = max(start, weight);
            end += weight;
        }

        int ans = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (isPossibleSol(weights, days, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};
