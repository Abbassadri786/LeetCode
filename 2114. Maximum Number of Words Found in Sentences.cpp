class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int cnt = 0;
        int maxi = 0;
        for(int i=0; i<sentences.size(); i++){
            cnt = 1;
            for(char ch :sentences[i]){
                if(ch == ' '){
                    cnt++;
                }
            }
            maxi = max(cnt, maxi);
        }

        return maxi;
    }
};
