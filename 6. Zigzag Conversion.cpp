class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 0 || numRows == 1){
            return s;
        }
        vector<string> zigzag(numRows);
        int i = 0; // To traverse through whole string 
        int row = 0;
        bool direction = true; // Considering top-bottom by default
        while(true){
            if(direction){
                while(row < numRows && i<s.size()){
                    zigzag[row++].push_back(s[i++]);
                }
                row = numRows - 2;
            }
            else{
                while(row >= 0 && i<s.size()){
                    zigzag[row--].push_back(s[i++]);
                }
                row = 1;
            }
            direction = !direction;
            if(i>=s.size()) break;
        }
        string ans = "";
        for(int i = 0; i < zigzag.size(); i++){
            ans += zigzag[i];
        }
        return ans;
    }
};
