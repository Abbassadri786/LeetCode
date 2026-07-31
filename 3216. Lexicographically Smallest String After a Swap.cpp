class Solution {
public:
    string getSmallestString(string s) {
        // My approach:
        // Traverse the string from left to right.
        // For every adjacent pair:
        // 1. Check if both digits have the same parity (both even or both odd).
        // 2. If they do and the left digit is greater than the right digit,
        //    swapping them will make the string lexicographically smaller.
        // 3. Perform the swap and return immediately since only one swap is allowed.

        for (int i = 0; i < s.size() - 1; i++) {
            int curr = s[i] - '0';
            int next = s[i + 1] - '0';

            if ((curr % 2 == next % 2) && (curr > next)) {
                swap(s[i], s[i + 1]);
                return s;
            }
        }

        return s;
    }
};
