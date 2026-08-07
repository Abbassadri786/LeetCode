class Solution {
public:
    int nthUglyNumber(int n) {

        vector<int> ugly(n);

        // First ugly number
        ugly[0] = 1;

        // Three pointers
        int i2 = 0;
        int i3 = 0;
        int i5 = 0;

        for(int i = 1; i < n; i++) {

            // Next possible ugly numbers
            int next2 = ugly[i2] * 2;
            int next3 = ugly[i3] * 3;
            int next5 = ugly[i5] * 5;

            // Choose the smallest
            int nextUgly = min({next2, next3, next5});

            ugly[i] = nextUgly;

            // Move all pointers that generated nextUgly
            if(nextUgly == next2) i2++;
            if(nextUgly == next3) i3++;
            if(nextUgly == next5) i5++;
        }

        return ugly[n - 1];
    }
};
