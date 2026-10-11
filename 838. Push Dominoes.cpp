// Approach 1: Naive
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        string ans = dominoes;

        for (int i = 0; i < n; i++) {

            if (dominoes[i] != '.')
                continue;

            int left = i - 1;
            int right = i + 1;

            // Find the nearest non-dot domino on the left
            while (left >= 0 && dominoes[left] == '.') {
                left--;
            }

            // Find the nearest non-dot domino on the right
            while (right < n && dominoes[right] == '.') {
                right++;
            }

            char l = (left >= 0) ? dominoes[left] : ' ';
            char r = (right < n) ? dominoes[right] : ' ';

           if(l == 'R' && r == 'L'){
            if(right - left > 2){
                ans[i] = (i -left < right - i) ? 'R' : (i - left > right - i)? 'L' : '.';
            }
           }
           else if(l == 'R' && r != 'L'){
            ans[i] = 'R';
           }
           else if(l != 'R' && r == 'L'){
            ans[i] = 'L';
           }
        }

        return ans;
    }
};

// Approach 2: force propagation simulation. When a domino falls to the right (R), it exerts a decreasing force on the dominoes to its right. Similarly, a left-falling domino (L) pushes to the left. Neutral dominoes (.) can be affected by both sides. If both sides exert equal force, the domino remains upright.

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> forces(n, 0);

        // Left to Right pass (apply rightward forces)
        int force = 0;
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'R') force = n;
            else if (dominoes[i] == 'L') force = 0;
            else force = max(force - 1, 0);
            forces[i] += force;
        }

        // Right to Left pass (apply leftward forces)
        force = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (dominoes[i] == 'L') force = n;
            else if (dominoes[i] == 'R') force = 0;
            else force = max(force - 1, 0);
            forces[i] -= force;
        }

        string result;
        for (int f : forces) {
            if (f > 0) result += 'R';
            else if (f < 0) result += 'L';
            else result += '.';
        }

        return result;
    }

};
