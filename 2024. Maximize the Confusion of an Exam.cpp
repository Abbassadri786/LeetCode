//Approach 1
class Solution {
private:
    int solve(string str, int k, char ch) {
        int i = 0, j = 0, res = 0, cnt = 0;

        while(j < str.size()) {

            // Count occurrences of the character we are allowed to flip
            if(str[j] == ch) cnt++;

            // Shrink the window if flips required exceed k
            while(cnt > k) {
                if(str[i] == ch) cnt--;
                i++;
            }

            // Update the maximum valid window length
            res = max(res, j - i + 1);

            j++;
        }

        return res;
    }

public:
    int maxConsecutiveAnswers(string str, int k) {
        return max(solve(str, k , 'T'), solve(str, k , 'F'));
    }
};

//Appraoch 2
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i = 0, j = 0, res = 0;
        unordered_map<char, int> mp;

        while(j < answerKey.size()) {

            // Include the current character in the window
            mp[answerKey[j]]++;

            // Shrink the window if both T and F occur more than k times
            while(min(mp['T'], mp['F']) > k) {
                mp[answerKey[i]]--;
                i++;
            }

            // Update the maximum valid window length
            res = max(res, j - i + 1);

            j++;
        }

        return res;
    }
};
