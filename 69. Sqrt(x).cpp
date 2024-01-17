class Solution {
public:
    int mySqrt(int x) {
        //By Applying Binary Search

        if(x == 0 || x == 1){
            return x;
        }
        int low = 0;
        int high = x;  // Corrected initialization
        int ans = 0;

        while(low <= high){
            int mid = low + (high - low) / 2;
            long long square = static_cast<long long>(mid) * mid;

            if(square <= x){
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
