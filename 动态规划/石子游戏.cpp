struct Pair {
    int fir, sec;
};
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int len = piles.size();
        vector<vector<Pair> > dp(len, vector<Pair>(len));
        //初始化对角线 
        for(int i = 0; i < len; ++i){
            dp[i][i].fir = piles[i];
            dp[i][i].sec = 0;
        }
        //斜着遍历
        //对于先手 选择最右边 or 选择最左边 （但选的时候是 后方）
        //对于后方 看先手哪一边
        for(int l = 2; l <= len; ++l){
            for(int i = 0; i <= len-l; ++i){
                int j = l + i - 1;
                int left = piles[i] + dp[i+1][j].sec;
                int right = piles[j] + dp[i][j-1].sec;
                // 对于后方看先手选哪一边
                if (left > right) {
                    dp[i][j].fir = left;
                    dp[i][j].sec = dp[i+1][j].fir;
                } else {
                    dp[i][j].fir = right;
                    dp[i][j].sec = dp[i][j-1].fir;
                } 
            }
        }
        Pair res = dp[0][len-1];
        return (res.fir - res.sec > 0? true:false);
    }
};
