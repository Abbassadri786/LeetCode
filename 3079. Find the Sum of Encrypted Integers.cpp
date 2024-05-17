class Solution {
public:
    int encrypt(int num){
        int max_elem = INT_MIN;
        int len = 0;
        while(num != 0){
            max_elem = max(max_elem, num % 10);
            num /= 10;
            len++;
        }
        int elem = 0;
        for(int i = 0; i < len; i++){
            elem = elem * 10 + max_elem;  
        }
        return elem;
    }

    int sumOfEncryptedInt(vector<int>& nums) {
        int sum = 0;
        for(int itr: nums){
            sum += encrypt(itr);
        }

        return sum;
    }
};
