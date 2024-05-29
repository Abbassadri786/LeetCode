class Solution {
public:
    int countDigits(int num) {
        int cnt = 0;
        int temp = abs(num); // Handle negative numbers
        while (temp > 0) {
            int rem = temp % 10;
            if (rem != 0 && num % rem == 0) { // Check if the digit is not zero
                cnt++;
            }
            temp /= 10;
        }
        return cnt;
    }
};
