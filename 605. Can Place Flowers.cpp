class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        
        for (int i = 0; i < len && n > 0; ++i) {
            if (flowerbed[i] == 0) {
                // Check neighbors or boundary conditions
                bool leftEmpty = (i == 0) || (flowerbed[i - 1] == 0);
                bool rightEmpty = (i == len - 1) || (flowerbed[i + 1] == 0);
                
                if (leftEmpty && rightEmpty) {
                    flowerbed[i] = 1; // Place a flower here
                    n--; // Reduce the number of flowers needed
                    i++; 
                }
            }
        }

        return n == 0;
    }
};
