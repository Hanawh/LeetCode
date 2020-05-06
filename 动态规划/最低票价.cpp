class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int maxday = days.back();
        vector<int> dp(maxday+1);
        int cur = 0;
        int day_7 = 0, day_30 = 0;
        for(int i=1; i<maxday+1; ++i){
            if(i != days[cur]) dp[i] = dp[i-1];
            else{
                cur ++ ;
                i-7 >= 0 ? (day_7 = dp[i-7]) : (day_7 = 0);
                i-30 >= 0 ? (day_30 = dp[i-30]) : (day_30 = 0);
                dp[i] = min({dp[i - 1] + costs[0], day_7 + costs[1], day_30 + costs[2]});
            }
        }
        return dp[maxday];
    }
};
