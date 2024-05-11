class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for (string op : operations) {
            if (op == "C") {
                st.pop();
            } else if (op == "D") {
                st.push(2 * st.top());
            } else if (op == "+") {
                int top = st.top();
                st.pop();
                int newtop = top + st.top();
                st.push(top);  
                st.push(newtop);
            } else {
                st.push(stoi(op));  
            }
        }

        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};
