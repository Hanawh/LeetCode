/*
输入: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
输出: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]

你能想出一个常数空间的解决方案吗？请使用原地算法
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return;
        int r = matrix.size(), c = matrix[0].size();
        int row = -1, col = -1;
        //先找到第一个为0的数所在行和列
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                if(matrix[i][j] == 0){
                    row = i;
                    col = j;
                    break;
                }
            }
            if(row != -1) //退出外层循环
                break;
        }
        if(row == -1 && col == -1) return; //矩阵没有0
        //用该0所在行和列去记录剩下的0的位置
        for(int i = row + 1; i < r; ++i){
            for(int j = 0; j < c; ++j){
                if(matrix[i][j] == 0){
                   matrix[row][j] = 0;
                   matrix[i][col] = 0;
                }
            }
        }
        for(int i = row + 1; i < r; ++i){
            if(matrix[i][col] == 0){
                for(int j = 0; j < c; ++j)
                    matrix[i][j] = 0;
            }
        }
        for(int j = 0; j < c; ++j){
            if(matrix[row][j] == 0){
                for(int i = 0; i < r; ++i)
                    matrix[i][j] = 0;
            }
        }

        for(int j = 0; j < c; ++j)
            matrix[row][j] = 0;
    }
};

int main(){
    vector<vector<int>> matrix = {{0,0,0,5},{4,3,1,4},{0,1,1,4},{1,2,1,3},{0,0,1,1}};
    Solution().setZeroes(matrix);
    for(auto &i : matrix){
        for(auto &j : i){
            cout << j <<' ';
        }
        cout << endl;
    }
    return 0;
}
