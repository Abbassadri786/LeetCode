class Solution {
public:
    bool isPossible(vector<int>& nums) {
        // solve this question using availablity and vaccancy map in which traverse thorugh whole array and keep freq of each elem if we found cosec elem then keep on decreasing that elem's freq
        unordered_map<int, int> freq;
        unordered_map<int, int> available;

        // Count frequency of every number
        for(int num : nums) {
            freq[num]++;
        }

        for(int num : nums) {

            // Already used in another subsequence
            if(freq[num] == 0) {
                continue;
            }

            // Use current number and think for next 2
            freq[num]--;

            // Extend an existing subsequence ending at num - 1
            if(available[num - 1] > 0) {

                available[num - 1]--;
                available[num]++;
            }
            else {
                // Start a new subsequence: num, num+1, num+2
                if(freq[num + 1] > 0 &&
                   freq[num + 2] > 0) {

                    freq[num + 1]--;
                    freq[num + 2]--;

                    // New subsequence now ends at num + 2
                    available[num + 2]++;
                }
                else {
                    // Cannot extend or create a valid sequence
                    return false;
                }
            }
        }

        return true;
    }
};
