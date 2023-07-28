class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(),0);
        stack<int> st;

        for(int i = 0; i < temperatures.size(); i++){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                int prevIndex = st.top();
                st.pop();
                ans[prevIndex] = i - prevIndex;
            }
            st.push(i);
        }
        return ans;
    }
};
