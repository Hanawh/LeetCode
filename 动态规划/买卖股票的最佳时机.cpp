class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //每天的状态：有股票 没有股票
        if(prices.empty()) return 0;
        int len = prices.size();
        int d_0,d_1;
        for(int i = 0; i < len; ++i){
            if(i == 0){ //第一天初始化
                d_0 = 0;
                d_1 = -prices[i];
            }
            else{
                d_0 = max(d_0, d_1+prices[i]);
                d_1 = max(d_1, -prices[i]);
            }
        }
        return d_0;
    }
};
