/*
输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出:  [1,2,4,7,5,3,6,8,9]
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int> >& matrix){
        vector<int> res;
        if(matrix.empty()) return res;
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = 0;
        for (int t = 0; t < m*n; ++t) //代表了次数
        {
            res.push_back(matrix[i][j]);
            if((i+j)%2 == 0) //和为偶数 向上移动
            {
                if(j == n-1) ++i;
                else if(i == 0) ++j;
                else
                {
                    i--;
                    j++;
                }
            }
            else
            {
                if(i == m-1) ++j;
                else if(j == 0) ++i;
                else
                {
                    i++;
                    j--;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int> >& matrix) {
        int row = matrix.size();
        if (row == 0) return {};
        int col = matrix[0].size();
        vector<int> res;
        //每一躺i与j的和是递增的
        int sum = 0; 
        while(sum < row + col){
            //由下到上
            //起点确定: 
            int x1 = (sum < row) ? sum : row - 1;
            int y1 = sum - x1;
            while(x1 >= 0 and y1 < col){
                res.push_back(matrix[x1][y1]);
                x1--;
                y1++;
            }
            sum++;
            if(sum >= row + col) break;
            
            //由上到下
            //起点确定
            int y2 = (sum < col) ? sum : col - 1;
            int x2 = sum - y2;
            while(y2 >= 0 and x2 < row){
                res.push_back(matrix[x2][y2]);
                y2--;
                x2++;
            }
            sum++;
        }
        return res;
    }
};
