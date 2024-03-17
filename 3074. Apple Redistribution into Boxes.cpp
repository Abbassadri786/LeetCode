class Solution {
public:
    int minimumBoxes(vector<int>& apples, vector<int>& capacity) {
        int appleSum = 0;
        for(int i = 0; i < apples.size(); i++){
            appleSum += apples[i];
        }
        sort(capacity.rbegin(), capacity.rend());
        
        int boxesUsed = 0;
        for(int i = 0; i < capacity.size(); i++){
            appleSum -= capacity[i];
            boxesUsed++;
            if(appleSum <= 0){
                break; // Correctly returns the number of boxes used
            }
        }
        return boxesUsed; // Indicates not enough capacity to store all apples
    }
};
