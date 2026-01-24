class Solution {
private:
    bool isPalindrome(string s, int start, int end){
        while(start <= end){
            if(s[start] != s[end]){
                return false;
            }
            start++, end--;
        }
        return true;
    }
    void partitioning(int idx, string s, vector<vector<string>>& ans, vector<string>& path){
        if(idx == s.length()){
            ans.push_back(path);
            return;
        }
        for(int i= idx; i<s.size(); i++){
            if(isPalindrome(s, idx, i)){
                path.push_back(s.substr(idx, i-idx+1));
                partitioning(i + 1, s, ans, path);
                path.pop_back();
            }
        }
        
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        partitioning(0, s, ans, path);

        return ans;
    }
};
