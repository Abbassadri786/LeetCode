class Solution {
private:
    int solve(string str, int k , char ch){
        int i = 0, j = 0, res = 0, cnt = 0;

        while(j < str.size()){
            if(str[j] == ch) cnt++;
            while( cnt>k ){
                if(str[i] == ch) cnt--;
                i++;
            }
            res = max(res, j-i+1);
            j++;
        }
        return res;
    }
public:
    int maxConsecutiveAnswers(string str, int k) {
        return max(solve(str, k , 'T'), solve(str, k , 'F'));
    }
};
