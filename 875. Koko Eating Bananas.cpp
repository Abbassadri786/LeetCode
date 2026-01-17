class Solution {
private:
    int findMax(vector<int>& piles){
        int maxi = INT_MIN;
        for(int x : piles){
            maxi = max(maxi, x);
        }
        return maxi;
    }

    long long hoursCal(vector<int>& piles, int hourly){
        long long totalHours = 0;
        for(int x : piles){
            totalHours += (x + hourly - 1) / hourly;  // safe integer ceil
        }
        return totalHours;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findMax(piles);

        while(low <= high){
            int mid = low + (high - low) / 2;
            long long totalHours = hoursCal(piles, mid);

            if(totalHours <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};
