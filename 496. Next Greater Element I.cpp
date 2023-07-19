class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
     
        int n = nums1.size();
        int m = nums2.size();
        int i;
        unordered_map<int,int>mp;
        stack<int>st;
        for(i=0;i<m;i++)
        {
            while(st.size() && nums2[i] > st.top())
            {
                mp[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        
        for(i=0;i<n;i++)
        {
            if(mp.find(nums1[i]) != mp.end())
            {
                nums1[i] = mp[nums1[i]];
            }
            else
            {
                nums1[i] = -1;
            }
        }
        return nums1;
    }
};
