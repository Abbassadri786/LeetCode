class Solution {
public:
    bool isPowerOfThree(int n) {
      if(n == 0){
          return false;
      }
      if(n == 1){
          return true;
      }  
      long long num = 1;
      vector<long long> powThree;
      for(long long i = 1; i < n; i++){
          num *= 3;
          if(num > n){
              break;
          }
        powThree.push_back(num);
      }
      for(long long i = 0; i < powThree.size(); i++){
          if(powThree[i] == n){
              return true;
          }
      }
      return false;
    }
};
