class Solution {
public:
    int arrangeCoins(int n) {
        int i = 1; // i ko 1 se initialize kiya kyoki row meri 1 se start hogi
        while (n >= i) {
            n -= i;  // Subtract the coins used for the current row
            i++;     // Move to the next row, which requires one more coin
        }
        return i - 1;  
    }
};
