class Solution {
public:
    int majorityElement(vector<int>& nums) {
    unordered_map<int,int> freq;
    int elem = 0;
    for(int i=0; i<nums.size(); i++){
        freq[nums[i]]++;

        if(freq[nums[i]] > nums.size()/2){
            elem = nums[i];
        }
    }
    return elem;
    }
};
