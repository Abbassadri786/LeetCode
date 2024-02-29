class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> left(n), right(n);
        left[0] = height[0];
        right[n - 1] = height[n - 1];

        // Calculate the maximum height from the left side
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], height[i]);
        }

        // Calculate the maximum height from the right side
        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], height[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += max(0, min(left[i], right[i]) - height[i]);
        }

        return ans;
    }
};
