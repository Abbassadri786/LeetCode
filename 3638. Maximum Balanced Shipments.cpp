class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        
        int ans = 0;
        int n = weight.size();

        for(int i = 0; i < n; i++) {

            // Maximum weight in current shipment
            int maxi = weight[i];

            // Extend current shipment until it becomes balanced
            while(i < n) {

                maxi = max(maxi, weight[i]);

                // Shipment is balanced if last element
                // is smaller than the maximum seen so far
                if(weight[i] != maxi) {
                    ans++;
                    break;
                }

                i++;
            }
        }

        return ans;
    }
};
