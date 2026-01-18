class Solution {
private:
    bool possible(vector<int>& weights, int days, int cap){
        // to track load in a ship daywise
        int load = 0;
        //lets start days required to laod ship be 1
        int calDay = 1;
        for(int i=0; i<weights.size(); i++){
            // check if load till now + curr weight does not exceed min capacity 
            if(load + weights[i] > cap){
                // increment days to load
                calDay++;
                // if load calculated > curr weight then just keep that in load
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        
        return calDay <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxCap = 0, maxi = INT_MIN;
        int n= weights.size();

        for(int i=0; i<n; i++){
            maxCap += weights[i];
            maxi = max(maxi, weights[i]);
        }
        int low = maxi, high = maxCap;

        while(low <= high){
            int mid = (low+high) / 2;

            if(possible(weights, days, mid)){
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }
};
