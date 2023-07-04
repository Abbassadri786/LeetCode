#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        int freq[26] = {0};

        // Determining the frequency of each character in the given string
        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
        }

        // Find the character with the maximum frequency
        int maxFreq = 0;
        char maxChar = 'a';
        for (int i = 0; i < 26; i++) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
                maxChar = i + 'a';
            }
        }

        // Check if it's possible to reorganize the string
        if (maxFreq > (s.length() + 1) / 2) {
            return "";
        }

        // Create a vector to store the characters and their frequencies
        vector<pair<int, char>> sortedChars;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                sortedChars.push_back(make_pair(freq[i], i + 'a'));
            }
        }

        // Sort the characters based on frequency in descending order
        sort(sortedChars.rbegin(), sortedChars.rend());

        // Reorganize the string
        int index = 0;
        for (auto& p : sortedChars) {
            int count = p.first;
            char c = p.second;
            while (count > 0) {
                if (index >= s.length()) {
                    index = 1;
                }
                s[index] = c;
                index += 2;
                count--;
            }
        }

        return s;
    }
};
