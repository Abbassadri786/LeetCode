class Solution {
public:
    string reverseStr(string s, int k) {
        int i=0, n = s.length();

        while(i < n){
            int j = min(i+k-1, n-1);

            int start = i, end = j;
            while(start <= end){
                swap(s[start],s[end]);
                start++;
                end--;
            }

            i += 2*k;
        }

        return s;
    }
};
