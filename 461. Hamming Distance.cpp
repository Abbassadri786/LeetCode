class Solution {
public:
    int hammingDistance(int x, int y) {
        int xorRes = x ^ y;
        int cnt = 0;
        while( xorRes != 0){
            cnt += xorRes & 1;
            xorRes >>= 1;
        }

        return cnt;
    }
};
