class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(begin(happiness), end(happiness), greater<int>());
        int i = 0;
        long long res = 0;

        // Is Approach me aise he ki Pehle Vector ko Decreasing Order me sort karrliya he
        // Uske baad Ham Sabse bade Elem ko pick karrke add karte jaa rhe he Res me
        // fir 1 li waaali line loop ki usme ham next curr element ko - i karr rhe he bass
        // sirf next max element ko hi - i kar rhe he kyuki hame usi ko select karrke Res me add karrna he

        while(k--) {
            happiness[i] = max(happiness[i] - i, 0);
            res += happiness[i++];
        }

        return res;
    }
};
