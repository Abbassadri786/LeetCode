class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int totalCandies = 0;
        vector<int> candies(n,1);
        if(n == 0) return 0;

        //Traversing Left to Right
        for(int i=1; i<n; i++){
            if(ratings[i] > ratings[i-1]){
                candies[i] = candies[i-1] + 1;
            }
        }

        //Traversing Right to Left
        for(int i=n-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]){
                candies[i] = max(candies[i], candies[i+1]+1);
            }
        }
        for(auto& itr: candies){
            totalCandies += itr;
        }

        return totalCandies;
    }
};

// Approach 2:
class Solution {
  public:
    int candy(vector<int> &arr) {
        int n = arr.size();
        if(n == 0) return 0;

        // Step 1: Left to Right pass (same as your approach)
        vector<int> left(n, 1);
        for(int i = 1; i < n; i++) {
            if(arr[i] > arr[i - 1]) {
                left[i] = left[i - 1] + 1;
            } else {
                left[i] = 1;
            }
        }

        // Step 2: Right to Left pass (optimized - no right array)
        int sum = 0;
        int right = 1;  // candies needed from right side for last child

        // Last index contribution
        sum += max(left[n - 1], right);

        for(int i = n - 2; i >= 0; i--) {
            int curr;

            // If current rating > next rating, need more candies than right neighbor
            if(arr[i] > arr[i + 1]) {
                curr = right + 1;
            } else {
                curr = 1;
            }

            sum += max(left[i], curr);

            // update right for next iteration (moving left)
            right = curr;
        }

        return sum;
    }
};
