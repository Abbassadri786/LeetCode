class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reversed = 0;
        int bitsToReverse = 32;
        
        while (bitsToReverse--) {
            reversed = (reversed << 1) | (n & 1);
            n >>= 1;
        }
        
        return reversed;
    }
};
