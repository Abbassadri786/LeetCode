class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; i++) {
            if (isSelfDividing(i)) {
                res.push_back(i);
            }
        }
        return res;
    }
    
    bool isSelfDividing(int num) {
        int original = num;
        while (num > 0) {
            int digit = num % 10;
            if (digit == 0 || original % digit != 0) {
                return false;
            }
            num /= 10;
        }
        return true;
    }
};
