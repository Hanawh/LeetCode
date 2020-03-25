class Solution {
public:
    int surfaceArea(vector<vector<int> >& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int res = 0;
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                int num = grid[i][j];
                if(num>0){
                    res += num*4+2;
                    if(i>0) res -= min(num, grid[i-1][j]) * 2;
                    if(j>0) res -= min(num, grid[i][j-1]) * 2;
                }
            }
        }
        return res;
    }
};
