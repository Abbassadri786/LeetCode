class Solution {
public:
    string decodeString(string s) {
        stack<int> numberStack;
        stack<string> strStack;

        string currentStr = "";
        int currentNum = 0;

        int i = 0;
        while (i < s.length()) {
            if (s[i] == '[') {
                numberStack.push(currentNum);
                strStack.push(currentStr);

                currentNum = 0;
                currentStr = "";
            } else if (s[i] == ']') {
                int repeatTimes = numberStack.top();
                numberStack.pop();

                string repeatedStr = "";
                for (int j = 0; j < repeatTimes; j++) {
                    repeatedStr += currentStr;
                }
                currentStr = strStack.top() + repeatedStr;
                strStack.pop();

            } else if (isdigit(s[i])) {
                currentNum = currentNum * 10 + (s[i] - '0');

            } else {
                currentStr += s[i];
            }
            i++;
        }
        return currentStr;
    }
};
