//Approach: 1
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> bitCount(32,0);
        int ans = INT_MAX;
        int currOR = 0;
        int left = 0;

        for(int right = 0; right < nums.size(); right++){
            //cnt set bits in nums[right]
            for(int bit = 0; bit < 32; bit++){
                if(nums[right] & (1 << bit)) // (1<<bit)is used for bitmask
                // '&' operator is used to extract set bit
                bitCount[bit]++;
            }

            //cal currOR
            currOR = 0;
            for(int bit = 0; bit < 32; bit++){
                if(bitCount[bit] > 0){
                    currOR |= (1 << bit ); 
                }
            }

            //shrink window
            while(left <= right && currOR >=  k){
                ans = min(ans, right - left + 1);
                for(int bit = 0; bit <32; bit++){
                    if(nums[left] & (1 << bit))
                    bitCount[bit]--;
                }
            left++;
            //cal currOR
            currOR = 0;
            for(int bit = 0; bit < 32; bit++){
                if(bitCount[bit] > 0){
                    currOR |= (1 << bit);
                }
            }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

//Approach : 2

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> bitCount(32,0);
        int ans = INT_MAX;
        int currOR = 0;
        int left = 0;

        for(int right = 0; right < nums.size(); right++){
            currOR |= nums[right];
            //cnt set bits in nums[right]
            for(int bit = 0; bit < 32; bit++){
                if(nums[right] & (1 << bit)) // (1<<bit)is used for bitmask
                // '&' operator is used to extract set bit
                bitCount[bit]++;
            }

            //shrink window
            while(left <= right && currOR >=  k){
                ans = min(ans, right - left + 1);

                int updatedOR = 0;
                for(int bit = 0; bit <32; bit++){
                    if(nums[left] & (1 << bit))
                        bitCount[bit]--;
                    if(bitCount[bit] > 0){
                        updatedOR |= (1 << bit);
                    }
                }
                currOR = updatedOR;
                left++;

                }
            }

        return ans == INT_MAX ? -1 : ans;
    }
};
