class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 1);
        for(int i=1; i<n+1; ++i){
            for(int j=1; j<i; ++j){
                dp[i] = max({dp[i], (i-j)*dp[j], (i-j)*j}); //dp代表拆解后的乘机最大值 拆或者不拆 
            }
        }
        return dp[n];
    }
};
