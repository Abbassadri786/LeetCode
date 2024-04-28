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
