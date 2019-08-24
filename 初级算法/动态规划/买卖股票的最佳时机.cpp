/*
输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public: 
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int profit = 0, maxpro = 0, minBuy = prices[0], sell = prices[0];
        for(auto i = 1; i < prices.size(); ++i){
            if(prices[i] < minBuy){
                minBuy = prices[i]; 
                sell = prices[i];
                if(profit > maxpro){
                    maxpro = profit;
                }
            }
            else{
                if(prices[i] > sell){
                    profit = prices[i] - minBuy;
                    sell = prices[i];
                }
            }
        }
        return max(profit, maxpro);
    }
};

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout << Solution().maxProfit(prices) << endl;
}
