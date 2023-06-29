class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int>pop(2060);
        for(auto i: logs){
            //increment the population count at the birth year i[0] by 1 and decrement the population count at the death year i[1] by 1.
            pop[i[0]]++;
            pop[i[1]]--;
        }
        int maxi = 0;
        int year_index = -1;

        for(int i = 1950; i <= 2050; i++){
            //update the population count by adding the population count of the previous year
            pop[i] += pop[i-1];
            if(pop[i] > maxi){
                maxi = pop[i];
                year_index = i;
            }
        }
        return year_index;
    }
};
