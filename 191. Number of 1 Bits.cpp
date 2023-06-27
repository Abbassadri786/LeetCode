class Solution {
public:
    // APPROACH - 1
    // int hammingWeight(uint32_t N) {
    //     int ans = 0;
    //     while(N != 0){
    //         ans += N % 2;
    //         N = N / 2;
    //     }
    //     return ans;
    // }
    // APPROACH - 2
    int hammingWeight(uint32_t N){
        int count = 0;
        while(N){
            if(N & 1)count++;
            N = N>>1;
        }
        return count;
    }
};
