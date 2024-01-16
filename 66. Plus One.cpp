#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int size = digits.size();
        
        for (int i = size - 1; i >= 0; --i) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i]++;
                return digits;
            }
        }
        // If we are here, all digits were 9, and we need to carry over.
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
