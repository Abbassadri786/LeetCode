class Solution {
public:
    string reverseVowels(string s) {
        int l = 0, h = s.size()-1;

        while(l < h){
            if((s[l]=='A'|| s[l]=='E' || s[l]=='I' || s[l]=='O' || s[l]=='U'|| s[l]=='a'|| s[l]=='e' || s[l]=='i' || s[l]=='o' || s[l]=='u') && (s[h]=='A'|| s[h]=='E' || s[h]=='I' || s[h]=='O' || s[h]=='U'|| s[h]=='a'|| s[h]=='e' || s[h]=='i' || s[h]=='o' || s[h]=='u')){
                swap(s[l],s[h]);
                l++,h--;
            }
            else if (!(s[l]=='A'|| s[l]=='E' || s[l]=='I' || s[l]=='O' || s[l]=='U'|| s[l]=='a'|| s[l]=='e' || s[l]=='i' || s[l]=='o' || s[l]=='u')){
                l++;
            }
            else{
                h--;
            }
        }
        return s;
        
    }
};
