class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size(), temp = 0, oneCount = 0;
        vector<int> ans(n);
        // Left pass
        for(int i=0; i<n; i++){
            ans[i] = temp;
            oneCount += boxes[i] == '1';
            temp += oneCount;

        }
      //Reset Counters
        temp = oneCount = 0;
        //Right pass
        for(int i = n - 1; i>=0; i--){
            ans[i] += temp;
            oneCount += boxes[i] == '1';
            temp += oneCount;
        }

        return ans;
        

    }
};
