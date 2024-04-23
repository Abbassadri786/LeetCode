class Solution {
public:
    bool isPerfectSquare(int num) {
       if(num < 2){
        return true;
       }
       long start = 1, end = num/2, mid, squared;

       while(start <= end){
            mid = start + (end - start)/2;
            squared = mid * mid;

            if(squared == num){
                return true;
            }
            if(squared > num){
                end = mid -1;
            }
            else{
                start = mid +1;
            }
       }
       return false; 
    }
};
