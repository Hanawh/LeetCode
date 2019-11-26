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

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        queue<pair<int, int> > q;
        if(grid.empty()) return 0;
        int res=0, row = grid.size(), col = grid[0].size();
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(grid[i][j]=='1'){ 
                    q.push(make_pair(i,j));
                    res++;
                    //探索所有邻接陆地
                    while(!q.empty()){
                        pair<int, int> temp = q.front();
                        q.pop();
                        int x = temp.first;
                        int y = temp.second;
                        if(grid[x][y]=='0') continue;
                        //将该陆地的所有邻接陆地入队
                        grid[x][y] = '0'; //已探索
                        if(isIsland(x-1,y,row,col)) q.push(make_pair(x-1,y));
                        if(isIsland(x+1,y,row,col)) q.push(make_pair(x+1,y));
                        if(isIsland(x,y-1,row,col)) q.push(make_pair(x,y-1));
                        if(isIsland(x,y+1,row,col)) q.push(make_pair(x,y+1));
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
