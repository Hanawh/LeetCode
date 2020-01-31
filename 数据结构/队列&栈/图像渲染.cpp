/*
输入: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
输出: [[2,2,2],[2,2,0],[2,0,1]]
解析: 
在图像的正中间，(坐标(sr,sc)=(1,1)),
在路径上所有符合条件的像素点的颜色都被更改成2。
注意，右下角的像素没有更改为2，
因为它不是在上下左右四个方向上与初始点相连的像素点。

111
110
101
是否相同
是否相连
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int newColor) {
        int row = image.size();
        int col = image[0].size();
        int target_value = image[sr][sc]; //目标替换值
        if(target_value == newColor) return image;
        
        queue<pair<int, int> > q;
        q.push(make_pair(sr, sc));

        while(!q.empty()){
            pair<int, int> temp = q.front();
            q.pop();
            int r = temp.first;
            int c = temp.second;
            image[r][c] = newColor;
            if(r-1 >= 0  and image[r-1][c] == target_value) q.push(make_pair(r-1,c));
            if(r+1 < row and image[r+1][c] == target_value) q.push(make_pair(r+1,c));
            if(c-1 >= 0  and image[r][c-1] == target_value) q.push(make_pair(r,c-1));
            if(c+1 < col and image[r][c+1] == target_value) q.push(make_pair(r,c+1));
        }
        return image;
    }
};
