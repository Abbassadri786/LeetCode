// Optimized way storing past results DP
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

// Un-Optimized way - after removing all factors of 2, 3, and 5, the remaining number is 1, then it is ugly.
class Solution {
private:

    bool isUgly(int num){

        while(num % 2 == 0){
            num /= 2;
        }

        while(num % 3 == 0){
            num /= 3;
        }

        while(num % 5 == 0){
            num /= 5;
        }

        return num == 1;
    }

public:
    int nthUglyNumber(int n) {

        int cnt = 0;

        for(int i = 1;; i++){

            if(isUgly(i)){
                cnt++;
            }

            if(cnt == n){
                return i;
            }
        }

        return 0;
    }
};
