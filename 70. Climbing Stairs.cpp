class Solution {
public:
    int climbStairs(int n) {
        int climb =1;
        int a = 1;
        int b = 1;

        for(int i=1; i<n; i++){
            climb = a + b;
            a = b;
            b = climb;
        }
        return climb;
        
    }
};
