class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = INT_MIN;
        int minSoFar = prices[0];

        for(int i=0; i<prices.size(); i++){
            minSoFar = min(minSoFar, prices[i]);

            maxProfit = max(maxProfit, prices[i] - minSoFar);
        }
        return maxProfit;
    }
};
