class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int s = 0, e = arr.size()-1;
        vector<int>ans;
        while(e-s >= k){
            if(x - arr[s] > arr[e] - x){
                s++;
            }
            else{
                e--;
            }
        }
        for(int i=s; i<=e; i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};
