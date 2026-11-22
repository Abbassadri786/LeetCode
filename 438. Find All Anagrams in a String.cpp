class Solution {
private:
    bool allZero(vector<int>& freq){
        for(auto &i: freq){
            if(i != 0){
                return false;
            }
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<int> freq(26,0);
        for(int i=0; i<m; i++){
            freq[p[i] - 'a']++;
        }
        int i=0, j=0;
        vector<int> ans;
        while(j < n){
            // andar liya to freq ghatao
            freq[s[j] - 'a']--;
            if(j-i+1 == m){
                if(allZero(freq)){
                    ans.push_back(i);
                }
                freq[s[i] - 'a']++;
                i++;
            }
            j++;
        }

        return ans;
    }
};
