class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.size();
        vector<vector<int> > dp(len, vector<int>(len, 0));
        //初始化 i=j的时候都为1
        for(int i=0; i<len; ++i){
            dp[i][i] = 1;
        }

        // i<j
        for(int i=len-2; i>=0; i--){
            for(int j=i+1; j<len; j++){
                if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1] + 2;
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
                }
            }
        }
        return dp[0][len-1];
    }
};
