class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string temp;

            for (int i = 0; i < s.size(); i += k) {
                int sum = 0;

                int end = min(i + k, (int)s.size());

                for (int j = i; j < end; j++) {
                    sum += s[j] - '0';
                }

                temp += to_string(sum);
            }

            s = temp;
        }

        return s;
    }
};
