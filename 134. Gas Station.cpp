class Solution {
public:
    //Highly Optimized by Love Babbar
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Kaha se start hoga circuit
        int start = 0; 
        //Kitna Petrol Kam pad gaya
        int deficit = 0;
        //Kitna petrol bacha hua he
        int currBalance = 0;

        for(int i=0; i<gas.size(); i++){
            currBalance += gas[i] - cost[i];
            // Agar invalid he toh
            if(currBalance < 0){
                deficit += currBalance;
                start = i+1;
                currBalance = 0;
            }
        }
        if(deficit + currBalance >= 0){
            return start;
        }
        else{
            return -1;
        }
    }
};
