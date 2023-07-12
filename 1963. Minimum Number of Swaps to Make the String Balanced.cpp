class Solution {
public:
    int minSwaps(std::string s) {
        if (s.length() % 2 != 0) return -1;
        
        stack<char> st;
        for(char &ch:s){
          if(ch=='[')  st.push(ch);
          else if(!st.empty()) st.pop();
        }
        return (st.size()+1)/2;
    }
};
