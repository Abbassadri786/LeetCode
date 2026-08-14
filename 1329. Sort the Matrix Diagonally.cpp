class Solution {
public:
// core concept -> to traverse diagonally from top right to bottom left we use -> [i-j] 
// to mark and collect specific vector group in map
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        unordered_map<int, vector<int>> mp;

        // Group elements belonging to the same diagonal
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                mp[i - j].push_back(mat[i][j]);
            }
        }

        // Sort every diagonal
        for(auto &itr : mp) {
            sort(itr.second.begin(), itr.second.end());
        }

        // Fill matrix from bottom-right using largest elements first
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {

                mat[i][j] = mp[i - j].back();
                mp[i - j].pop_back();
            }
        }

        return mat;
    }
};
