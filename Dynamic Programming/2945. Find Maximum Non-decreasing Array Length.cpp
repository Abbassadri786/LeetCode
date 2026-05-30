class Solution {
public:
// Build the optimal partition ending at i
// ↓
// Compute the sum of its last segment
// ↓
// Find the earliest future position that can form
// a non-decreasing next segment
// ↓
// Record i as a valid previous cut for that position
    int findMaximumLength(vector<int>& nums) {
        int n = nums.size();

        // Prefix sum array for O(1) range sum queries
        vector<long long> prefix(n + 1, 0);
        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        // dp[i] = maximum number of valid segments using first i elements
        vector<int> dp(n + 1, 0);

        // last[i] = sum of the last segment in the optimal partition ending at i
        vector<long long> last(n + 1, 0);

        // best[i] = best previous cut position that can be used for state i
        vector<int> best(n + 2, 0);

        for(int i = 1; i <= n; i++) {

            // Propagate best cut position forward
            best[i] = max(best[i], best[i - 1]);

            // Form one new segment from (best[i] + 1 ... i)
            dp[i] = dp[best[i]] + 1;

            // Compute sum of the newly formed last segment
            last[i] = prefix[i] - prefix[best[i]];

            // Future segment sum must be >= current last segment sum
            // prefix[j] - prefix[i] >= last[i]
            // => prefix[j] >= prefix[i] + last[i]
            long long target = prefix[i] + last[i];

            // Find earliest future position satisfying the condition
            int j = lower_bound(
                        prefix.begin(),
                        prefix.end(),
                        target
                    ) - prefix.begin();

            // Mark i as a valid previous cut for position j
            if(j <= n) {
                best[j] = max(best[j], i);
            }
        }

        return dp[n];


    }
};
