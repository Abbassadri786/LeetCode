class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int dollar5 = 0;
        int dollar10 = 0;

        for(int i = 0; i < bills.size(); i++){
            if(bills[i] == 5){
                dollar5++;
            }

            else if(bills[i] == 10){
                if(dollar5 > 0){
                    dollar5--;
                    dollar10++;
                }
                else{
                    return false;
                }
            }

            else{
                if(dollar5 > 0 && dollar10 > 0){
                    dollar5--;
                    dollar10--;
                }
                else if(dollar5 >= 3){
                    dollar5 -= 3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
