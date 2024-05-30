class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (auto& row : image)
            reverse(row.begin(), row.end());
        for (auto& x : image) {
            for (auto& y : x)
                if (y == 0)
                    y = 1;
                else
                    y = 0;
        }
        return image;
    }
};
