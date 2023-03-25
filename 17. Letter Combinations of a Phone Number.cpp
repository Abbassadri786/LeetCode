class Solution {
public:
    void solve(vector<string> &ans, int idx, string res,string digits,vector<string>&mapping ){
        //Base case
        if(idx >= digits.length()){
            ans.push_back(res);
            return;
        }
        // 1 case solve baaki reccursion
        int digit = digits[idx] - '0';
        string value = mapping[digit];
        for(int i=0; i<value.size(); i++){
            char ch = value[i];
            //include
            res.push_back(ch);
            //reccursive call
            solve(ans, idx+1, res,digits,mapping);
            //backtracking
            res.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0){
            return ans;
        }
        int idx = 0;
        string res = "";
        vector<string> mapping(10);
        mapping[2]= "abc";
        mapping[3]= "def";
        mapping[4]= "ghi";
        mapping[5]= "jkl";
        mapping[6]= "mno";
        mapping[7]= "pqrs";
        mapping[8]= "tuv";
        mapping[9]= "wxyz";
        
        solve(ans, idx, res, digits, mapping);
        return ans;
    }
};
