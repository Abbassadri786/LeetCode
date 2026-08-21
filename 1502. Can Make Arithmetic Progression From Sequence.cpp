class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        
        // Sort elements
        sort(arr.begin(), arr.end());
        
        // Common difference between the first two elements
        int diff = arr[1] - arr[0];
        
        // Check if the difference remains the same
        for(int i = 2; i < arr.size(); i++) {
            if(arr[i] - arr[i - 1] != diff) {
                return false;
            }
        }
        
        return true;
    }
};
