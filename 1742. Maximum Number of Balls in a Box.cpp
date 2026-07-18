class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {

        unordered_map<int, int> mp;
        int maxi = 0;
        
        for(int i = lowLimit; i <= highLimit; i++) {

            int num = i;
            int sum = 0;

            while(num > 0) {
                sum += num % 10;
                num /= 10;
            }

            mp[sum]++;

            maxi = max(maxi, mp[sum]);
        }

        return maxi;
    }
};
