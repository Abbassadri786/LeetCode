class Solution {
public:
    int maximum69Number (int num) {
        string numStr = to_string(num);

        for (char &ch : numStr) {
            if (ch == '6') {
                ch = '9';
                break;
            }
        }

        return stoi(numStr);
    }
};
