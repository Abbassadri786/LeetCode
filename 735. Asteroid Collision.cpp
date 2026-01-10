class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // using list - removing and pusing element from end due to which order will be maintained and only 1 data structure will be required.
        int n = asteroids.size();
        vector<int> st;

        for(auto it: asteroids){
            if(it > 0) st.push_back(it);
            else{
                while(!st.empty() && st.back() > 0 && st.back() < -it){
                    st.pop_back();
                }
                if(!st.empty() && st.back() == -it){
                    st.pop_back();
                }
                else if(st.empty() || st.back() < 0){
                    st.push_back(it);
                }
            }
        }

        return st;
        
    }
};
