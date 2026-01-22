// Aprroach 1 using Boyer-Moore Majority Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int cnt = 1;

        for(int i=1; i<nums.size(); i++){
            if(nums[i] == candidate){
                cnt++;
            }
            else{
                cnt--;
                if(cnt == 0){
                    candidate = nums[i];
                    cnt = 1;
                }
            }
        }

        return candidate;
    }
};


//Approach 2: Using Hashmap count the freq > n/2
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
