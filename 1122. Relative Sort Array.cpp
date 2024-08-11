class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        unordered_map<int, int>mp;
        // Freq for first array
        for(int ele : arr1) mp[ele]++;
        // Now checking those elements in arr2 and inserting that elements in ans
        for(int ele : arr2){
            auto itr = mp.find(ele);
            ans.insert(ans.end(), itr->second, itr->first);
            itr->second = 0;
        }
        // Abb size se pata laga lo kitne anjaan elem he
        int size = ans.size();
        // Bache hue elements ko daaldo sort karrke ans ke peeche
        for(auto ele : mp){
            if(ele.second > 0){
                ans.insert(ans.end(), ele.second, ele.first);
            }
        }
        sort(ans.begin()+size,ans.end());

        return ans;
    }
};
