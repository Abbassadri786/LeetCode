class Solution {
public:
    int countPoints(string rings) {
         vector<set<char>> rods(10);  // Create a vector of sets to store rings on each rod

        for (int i = 0; i < rings.size(); i += 2) {
            char color = rings[i];
            int rod = rings[i + 1] - '0';
            rods[rod].insert(color);  // Insert the color into the corresponding rod's set
        }

        int count = 0;
        for (const auto& rod : rods) {
            if (rod.size() == 3) {  // Check if the rod has all three colors
                count++;
            }
        }

        return count;
    }
};
