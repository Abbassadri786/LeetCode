class Solution {
public:
    bool isPrime(int n){

        if(n < 2) return false;

        for(int i = 2; i * i <= n; i++){
            if(n % i == 0){
                return false;
            }
        }

        return true;
    }

    int nonSpecialCount(int l, int r) {

        int special = 0;

        // Only prime squares can be special
        for(int i = 2; 1LL * i * i <= r; i++){

            if(isPrime(i)){

                long long sq = 1LL * i * i;

                if(sq >= l){
                    special++;
                }
            }
        }

        return (r - l + 1) - special;
    }
};
