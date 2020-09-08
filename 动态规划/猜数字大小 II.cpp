class Solution {
public:
    int getMoneyAmount(int n) {
        if(n<=1) return 0;
        vector<vector<int> > dp(n+1, vector<int>(n+1)); //区间[i,j]内的最坏情况下的最小开销
        //当只有1个数的时候开销为0 

        //斜着遍历 当知道长度为1的区间后 才能知道长度为2的区间
        for(int l=2; l<=n; l++){
            for(int i=1; i<=n-l+1; i++){
                int j=l+i-1;
                int minval=INT32_MAX;
                for(int k=i; k<j; k++){ 
                    int val=k+max(dp[i][k-1], dp[k+1][j]);
                    minval=min(minval, val);
                }
                dp[i][j]=minval;
            }
        }
        return dp[1][n];
    }
};
