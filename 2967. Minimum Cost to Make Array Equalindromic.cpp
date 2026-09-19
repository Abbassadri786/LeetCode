class Solution {
public:
    bool isPalindrome(long long n) {
        string s = to_string(n);
        string rev = s;
        reverse(rev.begin(), rev.end());
        return s == rev;
    }

    long long getCost(vector<int>& nums, long long target) {
        long long cost = 0;

        for (int x : nums) {
            cost += abs((long long)x - target);
        }

        return cost;
    }

    long long minimumCost(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        long long median = nums[n / 2];

        // If median itself is palindrome
        if (isPalindrome(median)) {
            return getCost(nums, median);
        }

        // Find palindrome smaller than median
        long long lower = median - 1;
        while (!isPalindrome(lower)) {
            lower--;
        }

        // Find palindrome greater than median
        long long upper = median + 1;
        while (!isPalindrome(upper)) {
            upper++;
        }

        return min(getCost(nums, lower), getCost(nums, upper));
    }
};
