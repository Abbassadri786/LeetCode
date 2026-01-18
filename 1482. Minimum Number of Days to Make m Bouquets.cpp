class Solution {
private:
    bool possible(vector<int>& bloomDay, int days, int m, int k){
        int noBloom = 0;
        int cnt = 0;

        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= days){
                // to count no. contigous flowers
                cnt++;
            }
            else{
                // to track no. of bouquets can be made
                noBloom += (cnt/k);
                //reset the count here
                cnt = 0; 
            }
        }
        // after running above loop might be possible flower are bloomable and cnt>0 suppose at n-1
        noBloom += (cnt/k);
        return noBloom >=m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long)m*k > n) return -1;
        int mini = INT_MAX, maxi = INT_MIN;

        for(int i=0; i<n; i++){
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }

        int low = mini, high= maxi;
        while(low <= high){
            int mid = (low+ high)/2;

            if(possible(bloomDay, mid, m, k)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
        
    }
};
