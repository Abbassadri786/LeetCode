class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {

        vector<int> cnt(5, 0);

        int activeFrogs = 0;
        int maxFrogs = 0;

        unordered_map<char, int> pos = {
            {'c', 0},
            {'r', 1},
            {'o', 2},
            {'a', 3},
            {'k', 4}
        };

        for(char ch : croakOfFrogs) {

            int idx = pos[ch];

            if(idx == 0) {
                // New frog starts croaking
                cnt[0]++;
                activeFrogs++;

                maxFrogs = max(maxFrogs, activeFrogs);
            }
            else {
                // Invalid sequence order
                if(cnt[idx - 1] == 0) {
                    return -1;
                }

                // Consume previous stage
                cnt[idx - 1]--;

                if(idx == 4) {
                    // Finished croaking
                    activeFrogs--;
                }
                else {
                    // Move to next stage
                    cnt[idx]++;
                }
            }
        }

        // All frogs must finish
        if(activeFrogs != 0) {
            return -1;
        }

        return maxFrogs;
    }
};
