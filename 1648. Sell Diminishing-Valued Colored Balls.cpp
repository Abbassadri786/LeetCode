class Solution {
public:
// using binary search
    bool isPossible(vector<int>&inventory, int orders, int mid){
        // Checking if number of balls over threshold  of colours are under "orders"
        long long count = 0;
        for(auto a : inventory){
            if(a > mid)
                count += (a - mid);
        }
        return count <= orders;
    }
    int maxProfit(vector<int>& inventory, int orders) {
        int low = 0;
        int high = *max_element(inventory.begin(), inventory.end());
        int k = 0;
        int mod = (1e9) + 7;
        while(low <= high){
            int mid = (high - low) / 2  + low;
            if(isPossible(inventory, orders, mid)){
                high = mid - 1;
                k = mid;
            }else {
                low = mid + 1;
            }
        }

        // calculate the sum of all the balls of colors over threshold using Arithmetic Progression
        int numBallsSold = 0;
        long long totalProfit = 0;
        for(auto ele: inventory){
            if(ele > k){
                int nums = ele - k;
                // AP (first + last)*n/2 = sum of n terms
                totalProfit = ( totalProfit + 1LL *(k+1 + ele) * nums/2 ) % mod;
                numBallsSold += nums;
            }
        } 
        if(numBallsSold < orders){
            totalProfit  = ( totalProfit + 1LL *(orders - numBallsSold) * k ) % mod;
        }
        return totalProfit;
    }
};
