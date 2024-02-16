class Solution {
public:
    bool isHappy(int n) {
        int original_n = n; // Store the original value of n
        int sum = 0; // Initialize sum variable
        int rem; // Declare rem variable

        while (n != 1 && n != 4) { // Check for the condition to break the loop
            sum = 0; // Reset sum for each iteration
            while (n > 0) {
                rem = n % 10; // Calculate the remainder
                sum += rem * rem; // Add the square of the digit to sum
                n /= 10; // Move to the next digit
            }
            n = sum; // Update n with the new sum
        }

        return n == 1; // If n is 1, it's a happy number; otherwise, it's not
    }
};
