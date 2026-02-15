// Approach (Greddy): Always pick the box type with the maximum units per box first.

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();

        // Step 1: Sort by units per box in descending order (Greedy core)
        sort(boxTypes.begin(), boxTypes.end(),
             [](vector<int> &a, vector<int> &b) {
                 return a[1] > b[1]; // higher units per box first
             });

        int maxUnits = 0;

        // Step 2: Pick boxes greedily
        for(int i = 0; i < n; i++) {
            int boxes = boxTypes[i][0];
            int unitsPerBox = boxTypes[i][1];

            // If we can take all boxes of this type
            if(boxes <= truckSize) {
                maxUnits += boxes * unitsPerBox;
                truckSize -= boxes;
            }
            else {
                // Take only remaining truck capacity boxes
                maxUnits += truckSize * unitsPerBox;
                break; // truck is full
            }
        }

        return maxUnits;
    }
};
