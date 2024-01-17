class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        istringstream iss(s);
        string temp;

        // Extracting the Words out of S string.
        while (iss >> temp) {
            words.push_back(temp);
        }

        if (pattern.size() != words.size()) {
            return false;
        }

        unordered_map<char, string> m;
        set<string> st;

        for (int i = 0; i < words.size(); i++) {
            if (m.find(pattern[i]) == m.end()) {
                if (st.find(words[i]) != st.end()) {
                    return false;
                }
                m[pattern[i]] = words[i];
                st.insert(words[i]);
            } else {
                if (m[pattern[i]] != words[i]) {
                    return false;
                }
            }
        }

        return true;    
    }
};
