class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string row1 = "qwertyuiopQWERTYUIOP";
        string row2 = "asdfghjklASDFGHJKL";
        string row3 = "zxcvbnmZXCVBNM";
        unordered_set<char> set1(row1.begin(), row1.end());
        unordered_set<char> set2(row2.begin(), row2.end());
        unordered_set<char> set3(row3.begin(), row3.end());
        vector<string> ans;

        for (const string& word : words) {
            bool canType = true;
            int row = 0; // to assign row to first character of a word so that i can easily check for other remain char in that word
            // set2.find(c) != set2.end() iska matalb char mil gaya wo waale set me
            // set2.find(c) == set2.end() iska matlab char nahi mila pura end tak chala
            for (char c : word) {
                if (row == 0) {
                    if (set1.find(c) != set1.end()) row = 1;
                    else if (set2.find(c) != set2.end()) row = 2;
                    else if (set3.find(c) != set3.end()) row = 3;
                } else {
                    if ((row == 1 && set1.find(c) == set1.end()) ||
                        (row == 2 && set2.find(c) == set2.end()) ||
                        (row == 3 && set3.find(c) == set3.end())) {
                        canType = false;
                        break;
                    }
                }
            }

            if (canType) ans.push_back(word);
        }

        return ans;
    }
};
