class Solution {
public:
    int countAsterisks(string s) {
        int flag=0, count=0;
        for(char c:s){
            if(flag%2==0 && c=='*'){
                count++;
            }
            else if(c=='|'){
                flag+=1;
            }
        }
        return count;
    }
};
