class Solution {
public:
    bool checkIfPangram(string sentence) {
        // Create a boolean array to track presence of each letter
        bool seen[26] = {false};
        int count = 0;

        // Iterate over each character in the sentence
        for (char c : sentence) {
            int index = c - 'a';
            if (!seen[index]) {
                seen[index] = true;
                count++;
                // If all 26 letters are found, return true early
                if (count == 26) {
                    return true;
                }
            }
        }

        // Check if all 26 letters were found
        return count == 26;
    }
};
