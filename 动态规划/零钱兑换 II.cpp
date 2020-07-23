class Solution {
public:
    int change(int amount, vector<int>& coins) {
        /*
        //状态：面值为k的方式 (会重复，比如21 12)
        vector<int> dp(amount+1);
        dp[0] = 1;
        for(int i = 1; i <= amount; ++i){
            for(auto coin : coins){
                if(i-coin<0) continue;
                dp[i] += dp[i-coin];
            }
        }
        return dp[amount];
        */
        vector<int> dp(amount+1);
        dp[0] = 1;
        for(auto coin : coins){
            for(int i = 1; i <= amount; ++i){
                if(i-coin<0) continue;
                dp[i] += dp[i-coin];
            }
        }
        return dp[amount];
    }
};
