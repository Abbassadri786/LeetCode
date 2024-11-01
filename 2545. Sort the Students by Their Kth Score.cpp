class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
   //pehle traverse karo saaare vectors given indice tak
   //phir i ke saath jth ki value store karo => matlab uss vector ke number ke saath indice wali value rakho
   //fir vector ki sorting karo according to the greater value
   int student = score.size();
    vector<pair<int,int>> temp;

   for(int i=0; i<student; i++){
    temp.push_back({score[i][k],i}); 
   }
    sort(temp.rbegin(), temp.rend());
    vector<vector<int>> res;

    //now sort all the vectors in a vector according the vector number;
    for(auto &p : temp){
        res.push_back(score[p.second]);
    }
    return res;
}

};
