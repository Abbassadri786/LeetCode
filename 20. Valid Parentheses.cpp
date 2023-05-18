class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i=0; i<s.length(); i++){
            char ch = s[i];

            //For Opening Bracket
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }

            //For Closing Bracket
            else{
                if(!st.empty()){
                    char topCh = st.top();
                    if(ch == ')' && topCh == '('){
                        st.pop();
                    }
                    else if(ch == '}' && topCh == '{'){
                        st.pop();
                    }
                    else if(ch == ']' && topCh == '['){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
        
    }
};
