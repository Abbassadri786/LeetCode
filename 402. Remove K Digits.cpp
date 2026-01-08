class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.size();
        string res = "";
        for(int i=0 ;i< n; i++){
            while(k>0 && !st.empty() && (st.top() - '0') > (num[i] - '0')){
                k--;
                st.pop();
            }
            st.push(num[i]);
        }
        // still K!= 0 need to remove digits
        while(k>0){
         st.pop();
         k--;
        }

        if(st.empty()) return "0";
        // build string from stack
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        // remove leading zeros
        while(res.size() != 0 && res.back() == '0'){
            res.pop_back();
        }
        // reverse to correct order
        reverse(res.begin(), res.end());
        if(res.empty()) return "0";

        return res;

    }
};
