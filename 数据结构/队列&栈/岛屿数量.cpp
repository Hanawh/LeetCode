/*Input:
11110
11010
11000
00000

Output: 1

Input:
11000
11000
00100
00011

Output: 3
*/

class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        stack<pair<int, int> > q;
        if(grid.empty()) return 0;
        int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        int res=0, row = grid.size(), col = grid[0].size();
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(grid[i][j]=='1'){ 
                    q.push(make_pair(i,j));
                    res++;
                    //探索所有邻接陆地
                    while(!q.empty()){
                        auto [x, y] = q.top();
                        q.pop();
                        if(grid[x][y]=='0') continue;
                        //将该陆地的所有邻接陆地入队
                        grid[x][y] = '0'; //已探索
                        for(int i=0; i<4; ++i){
                            int newx = x+dir[i][0];
                            int newy = y+dir[i][1];
                            if(isIsland(newx, newy, row, col)) q.push(make_pair(newx, newy));
                        }
                    }
                }
            }
        }
        return res;
    }

    bool isIsland(int x, int y, int row, int col){
        if(x >= 0 && x < row && y >= 0 && y < col) return true;
        return false;
    }
};
