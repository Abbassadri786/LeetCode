class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        double low = 0.0, high = 1.0;
        int n = arr.size();
        
        while (low < high) {
            double mid = (low + high) / 2;
            int total = 0, p = 0;
            double maxFraction = 0.0;
            int num = 0, denom = 1;

            for (int q = 1; q < n; ++q) {
                while (p < n && arr[p] <= mid * arr[q]) {
                    if (arr[p] / (double)arr[q] > maxFraction) {
                        maxFraction = arr[p] / (double)arr[q];
                        num = arr[p];
                        denom = arr[q];
                    }
                    p++;
                }
                total += p;
            }

            if (total == k) {
                return {num, denom};
            } else if (total < k) {
                low = mid;
            } else {
                high = mid;
            }
        }
        
        return {}; // Should not reach here in valid inputs
    }
};
