class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) return false;  // A perfect number must be greater than 1

        int sum = 1;  // Start sum at 1 (1 is a divisor for all positive integers
        int sqrtNum = sqrt(num);  // Calculate the square root of num once

        for (int i = 2; i <= sqrtNum; i++) {  // Start loop from 2 to the square root of num
            if (num % i == 0) {  // If i is a divisor of num
                sum += i;  // Add i to sum
                int otherDivisor = num / i;  // Compute the corresponding pair divisor
                if (i != otherDivisor) {  // If i is not the square root of num
                    sum += otherDivisor; 
                }
            }
        }
        
        return sum == num;
    }
};
