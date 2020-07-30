class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int lenA = s1.size();
        int lenB = s2.size();
        if(lenA * lenB == 0) return lenA+lenB;
        vector<vector<int> > dp(lenA+1, vector<int>(lenB+1));
        for(int i=1; i<lenA+1; ++i){
            dp[i][0] = dp[i-1][0] + s1[i-1];
        }
        for(int j=1; j<lenB+1; ++j){
            dp[0][j] = dp[0][j-1] + s2[j-1];
        }
        for(int i=1; i<lenA+1; ++i){
             for(int j=1; j<lenB+1; ++j){
                 if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
                 else{
                     //把s1删除 或者把s2删除
                     dp[i][j] = min(dp[i-1][j]+s1[i-1], dp[i][j-1]+s2[j-1]);
                 }
             }
         }
         return dp[lenA][lenB];
    }
};
