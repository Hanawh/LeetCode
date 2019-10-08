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
