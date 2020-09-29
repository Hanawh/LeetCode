class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        //逆向思维：k步从外界到达i,j点
        //外层加一圈代表外界
        if(K==0) return 1.0;
        vector<vector<double> > dp_pre(N+4, vector<double>(N+4)); //0步从外界到达i,j点
        vector<vector<double> > dp_cur(N+4, vector<double>(N+4));
        vector<vector<int>> dxy{{-1,-2}, {-2,-1}, {1,-2}, {-2,1}, {-1,2}, {2,-1}, {1,2}, {2,1}};
        //init ： 0步从外界到达i,j点
        for(int i=2; i<=N+1; i++){
            for(int j=2; j<=N+1; j++){
                dp_pre[i][j] = 1;
            }
        }
        //遍历
        for(int k=1; k<=K; ++k){
            for(int i=2; i<=N+1; i++){
                for(int j=2; j<=N+1; j++){
                    double temp = 0.0;
                    for(int n=0; n<8; n++){
                        temp += dp_pre[i+dxy[n][0]][j+dxy[n][1]];
                    }
                    dp_cur[i][j] = temp/8.0;
                }
            }
            dp_pre = dp_cur;
        }
        return dp_cur[r+2][c+2];
    }
};
