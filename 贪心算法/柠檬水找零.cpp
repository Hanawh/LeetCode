class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
         vector<int> cash(2);
        for(int i = 0; i < bills.size(); ++i){
            switch (bills[i])
            {
            case 5:
                cash[0]++;
                break;
            case 10:
                if(cash[0]==0) return false;
                cash[0]--;
                cash[1]++;
                break;
            case 20:
                if(cash[1] != 0){
                    cash[1]--;
                    if(cash[0]==0) return false;
                    cash[0]--;
                }
                else{
                    if(cash[0]<3) return false;
                    cash[0] -= 3;
                }
                break;
            }
        }
        return true;
    }
};
