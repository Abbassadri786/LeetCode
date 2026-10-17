class Solution {
public:
    int minimumPossibleSum(int n, int target) {
        const long long MOD = 1000000007LL;

        long long a = min(1LL * n, target / 2LL);
        long long b = n - a;

        // Sum of numbers from 1 to a
        long long sum1 = a * (a + 1) / 2;

        // Sum of b numbers starting from target
        long long sum2 = b * (2LL * target + b - 1) / 2;

        return (sum1 + sum2) % MOD;
    }
};
