class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        // so its bbasically 2 pointer approach i will start from left which is the min token value and j will start from right which is max token value
        // if we need to increase the score we will reduce that token value from total power and increase the score
        // but if we need to increase the power (keeping in mind in future it will let us have more profitable score) so we need to loose the score
        sort(tokens.begin(), tokens.end());

        int i = 0, j = tokens.size() - 1;
        int score = 0, ans = 0;

        while (i <= j) {
            // Use smallest token to gain score
            if (power >= tokens[i]) {
                power -= tokens[i++];
                score++;
                ans = max(ans, score);
            }
            // Sacrifice score to gain maximum power
            else if (score > 0) {
                power += tokens[j--];
                score--;
            }
            else {
                break;
            }
        }

        return ans;
    }
};
