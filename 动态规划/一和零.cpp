class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        //先统计每个str中0,1的个数
        int len = strs.size();
        vector<vector<int> > count(len, vector<int>(2, 0));
        for(int i=0; i<len; ++i){
            int size = strs[i].size();
            for(int j=0; j<size; ++j){
                int ind = strs[i][j]-'0';
                count[i][ind]++;
            }
        }

        vector<vector<vector<int> > > dp(len+1, vector<vector<int> >(m+1, vector<int>(n+1, 0)));
        //背包 选当前字符串 或者 不选当前字符串
        for(int i=1; i<=len; ++i){
            for(int j=0; j<=m; ++j){
                for(int k=0; k<=n; ++k){
                    if(j >= count[i-1][0] and k >= count[i-1][1]){
                        dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-count[i-1][0]][k-count[i-1][1]]+1);
                    }
                    else
                        dp[i][j][k] = dp[i-1][j][k];
                }
            }
        }

        return dp[len][m][n];
    }
};
