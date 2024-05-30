class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        stack<char> st;

        for (char c : s) {
            if (c == '(') {
                if (!st.empty()) {
                    result += c;  // Add '(' to result only if stack is not empty
                }
                st.push(c);
            } else {
                st.pop();
                if (!st.empty()) {
                    result += c;  // Add ')' to result only if stack is not empty
                }
            }
        }

        return result;
    }
};
