class Solution {
public:
    void rotate(vector<vector<int>>& mat){
        int len = mat.size();
        for(int i=0; i<len; i++){
            for(int j=i; j<len; j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
        for(int i=0; i<len; i++){
            reverse(mat[i].begin(), mat[i].end());
        }
    }
    bool isequal(vector<vector<int>>& mat, vector<vector<int>>& target){
        int len = mat.size();
        for(int i=0; i<len; i++){
            for(int j=0; j<len; j++){
                if(mat[i][j] != target[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i=0; i<4; i++){
            if(isequal(mat,target)){
                return true;
            }
            rotate(mat);
        }
        return false;
    }
};
