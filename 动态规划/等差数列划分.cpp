class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int len = A.size();
        if(len < 3) return 0;
        vector<int> dp(len); //记录以该数字结尾的等差数列个数
        int res=0;
        for(int i=2; i<len; ++i){
            //前一个是等差数列
            if(dp[i-1] != 0 and A[i]-A[i-1]==A[i-1]-A[i-2]){
                dp[i] = dp[i-1];
            }
            //以当前元素向前推3个
            if(A[i]-A[i-1]==A[i-1]-A[i-2]){
                dp[i]++;
            }
            //上述过程可简写为： dp[i] = dp[i-1] + 1
            res += dp[i];
        }
        return res;
    }
};
