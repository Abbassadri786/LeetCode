class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int lastseen[3] = {-1, -1, -1};

        int cnt = 0;

        for(int i = 0; i < n; i++) {

            // Update the last seen index of current character
            lastseen[s[i] - 'a'] = i;

            // If we have seen all three characters at least once
            if(lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1) {

                // Find the minimum last seen index among a, b, c
                int minIndex = min(lastseen[0], min(lastseen[1], lastseen[2]));

                // Number of valid substrings ending at index i
                // = all starting positions from 0 to minIndex
                // = minIndex + 1 substrings
                cnt += (minIndex + 1);
            }
        }

        return cnt;
    }
};
