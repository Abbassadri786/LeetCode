class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        priority_queue<int> q;
        int zeroes = 0;
        int n = nums.size();
        long long ans = 0;
        int ones = 0;

        for(int i=0; i<n; i++){
            if(s[i] == '0' && zeroes == 0){
                while(ones > 0){
                    ans += q.top();
                    q.pop();
                    ones--;
                }
                q.push(nums[i]);
                zeroes++;
            }
            else if(s[i] == '0'){
                q.push(nums[i]);
                zeroes++;
            }
            else{
                q.push(nums[i]);
                ones++;
                zeroes = 0;
            }
        }

        while(ones > 0){
            ans += q.top();
            q.pop();
            ones--;
        }

        return ans;

    }
};
