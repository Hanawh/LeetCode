class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> f(m, vector<int>(n));
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if(matrix[i][j] == 1){
                    if(i == 0 || j == 0) f[i][j] = 1;
                    else{
                        f[i][j] = min({f[i][j - 1], f[i - 1][j], f[i - 1][j - 1]}) + 1;
                    }
                }
                res += f[i][j];
            }
        }
        return res;
    }
};
