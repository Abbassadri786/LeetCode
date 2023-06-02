class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        //First window of k size
        for(int i=0; i < k; i++){
            // Chote element remove karrdo
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            // Inserting index so that we can check out of window element
            dq.push_back(i);
        }
        //Store answer for first window
        ans.push_back(nums[dq.front()]);

        for(int i = k; i < nums.size(); i++){
            //Out of Window element ko remove kardiya
            if(!dq.empty() && i-dq.front() >= k){
                dq.pop_front();
            }
            // Chote element remove karrdo
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            // Inserting index so that we can check out of window element
            dq.push_back(i);
            // Current window ke element ko store karrna
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
