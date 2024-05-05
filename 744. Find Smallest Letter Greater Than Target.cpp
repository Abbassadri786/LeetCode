class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int mini = -1;
        int minDiff = INT_MAX; 
        
        for (int i = 0; i < letters.size(); i++) {
            int diff = letters[i] - target;
            if (diff > 0 && diff < minDiff) {
                minDiff = diff;
                mini = i;
            }
        }

        if (mini == -1) {
            return letters[0];
        }

        return letters[mini]; 
    }
};
