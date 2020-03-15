class Solution {
public:
    int maxAreaOfIsland(vector<vector<int> >& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int res = 0;
        int num;
        queue<pair<int, int> > q;
        int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(grid[i][j] == 1){
                    q.push(make_pair(i,j));
                    grid[i][j]=0;
                    num = 1;
                    while (!q.empty())
                    {
                        pair<int, int> curr = q.front();
                        q.pop();
                        for (int i = 0; i < 4; i++) {
                            int new_r = curr.first + dir[i][0], new_c = curr.second + dir[i][1];
                            if (new_r >= 0 && new_c >= 0 && new_r < row && new_c < col) {
                                if(grid[new_r][new_c] == 1){
                                    num++;
                                    q.push(make_pair(new_r, new_c));
                                    grid[new_r][new_c] = 0;
                                }
                            }
                        }
                    }
                res = max(res, num);     
                }
            }
        }
        return res;
    }
};
