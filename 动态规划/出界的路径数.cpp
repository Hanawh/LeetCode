class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        //逆向思维：k步从外界到达i,j点
        //外层加一圈代表外界
        if(N==0) return 0;
        long mod = 1000000007;
        vector<vector<long> > dp_pre(m+2, vector<long>(n+2)); //0步从外界到达i,j点
        vector<vector<long> > dp_cur(m+2, vector<long>(n+2));
        //init ： 0步从外界到达i,j点
        //第0行 第m+1行
        for(int r=0; r<m+2; r++){
            dp_pre[r][0] = 1;
            dp_pre[r][n+1] = 1;
        }
        //第0列 第n+1列
        for(int c=0; c<n+2; c++){
            dp_pre[0][c] = 1;
            dp_pre[m+1][c] = 1;
        }
        long sum = 0;
        //遍历
        for(int k=1; k<=N; ++k){
            for(int r=1; r<=m; r++){
                for(int c=1; c<=n; c++){
                    dp_cur[r][c] = (dp_pre[r-1][c]%mod+dp_pre[r+1][c]%mod+dp_pre[r][c-1]%mod+dp_pre[r][c+1]%mod)%mod;
                }
            }
            sum = (sum%mod + dp_cur[i+1][j+1]%mod)%mod;
            dp_pre = dp_cur;
        }
        return sum;
    }
};
