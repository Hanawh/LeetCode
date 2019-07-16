#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int profit=0,buy=prices[0];
        for(int i=1; i<prices.size(); ++i)
        {
            if(prices[i]<buy) buy=prices[i];
            else
            {
                profit += prices[i]-buy;
                buy = prices[i];
            }
        }
        return profit;
    }
};
int main()
{
    int nums[]={7, 1, 5, 3, 6, 4};
    vector<int> vec_nums(nums, nums + sizeof(nums) / sizeof(int));
    int profit = Solution().maxProfit(vec_nums);
    cout<<profit;
    return 0;
}
