class Solution {
public:
    int addDigits(int num) {
        while(num >= 10){
            int sum_digit = 0;
            while(num){
                int digit = num % 10;
                sum_digit += digit;
                num /= 10;
            }
            num = sum_digit;
        }

        return num;
    }
};
