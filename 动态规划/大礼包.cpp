class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs){
        //第一种情况：以原价购买
        int res = 0;
        for(int i=0; i<price.size(); ++i){
            res += price[i] * needs[i];
        }

        //第二种情况：只要某一个special的数量小于等于need的数量，我们就可以用该special
        for(auto &s : special){
            vector<int> temp(needs);
            for(int i=0; i<s.size(); ++i){
                if(i!=(s.size()-1)){
                    temp[i] = temp[i] - s[i];
                    if(temp[i] < 0) break;
                }
                else res = min(res, s[i]+shoppingOffers(price, special, temp));
            }
        }
        return res;
    }
};
