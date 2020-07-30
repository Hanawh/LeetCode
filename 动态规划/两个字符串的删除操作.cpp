class Solution {
public:
    int minDistance(string word1, string word2) {
        int lenA = word1.size();
        int lenB = word2.size();
        if(lenA * lenB == 0) return lenA+lenB;
        int dp[lenA+1][lenB+1];
        for(int i=0; i<lenA+1; ++i){
            dp[i][0] = i;
        }
        for(int j=0; j<lenB+1; ++j){
            dp[0][j] = j;
        }
        for(int i=1; i<lenA+1; ++i){
             for(int j=1; j<lenB+1; ++j){
                 if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                 else{
                     //把word1删除 或者把word2删除
                     dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
                 }
             }
         }
         return dp[lenA][lenB];
    }
};
