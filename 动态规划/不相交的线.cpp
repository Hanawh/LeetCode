class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int lenA = A.size();
        int lenB = B.size();
        vector<vector<int> > dp(lenA+1, vector<int>(lenB+1));
        for(int i=1; i<lenA+1; ++i){
             for(int j=1; j<lenB+1; ++j){
                 if(A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                 else{
                     dp[i][j] = max({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]});
                 }
             }
         }
         return dp[lenA][lenB];
    }
};

/*
0   0   1   2   4
0   0   0   0   0
1   0   1   1   1
4   0   1   1   2
2   0   1   2   2
*/
