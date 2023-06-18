class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int s = 0;
        int e = n - 1;
        int max_area = INT_MIN;

        while(s < e){
            int area = (e - s) * min(arr[s],arr[e]);
            max_area = max(max_area, area);

            if(min(arr[s],arr[e]) == arr[s]){
                s++;
            }
            else{
                e--;
            }
        }
        return max_area;        
    }
};
