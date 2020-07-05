class Solution {
public:
    bool isMatch(string s, string p) {
        int row = p.size();
        int col = s.size();
        vector<vector<bool> > dp(row+1, vector<bool>(col+1, false));
        dp[0][0] = true;
        for(int i=1; i<row+1; i++){
            if(p[i-1]=='*') dp[i][0]=true;
            else break;
        }

        for(int i=1; i<row+1; i++){
            for(int j=1; j<col+1; j++){
                if(p[i-1]=='?' or p[i-1] == s[j-1]){ //代替一个字符
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[i-1]=='*'){
                    //用 或 不用
                    dp[i][j] = dp[i][j-1] or dp[i-1][j];
                }
            }
        }
        return dp[row][col];
    }
};

