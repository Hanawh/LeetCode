/*
给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
 */
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    void rotate(vector<vector<int>>& matrix) {
      int n=matrix.size();
      for(int i=0; i<n/2; ++i)
        {
            for(int j=i; j<n-1-i; ++j)
            {
                int temp=matrix[i][j];
                matrix[i][j]=matrix[n-1-j][i];
                matrix[n-1-j][i]=matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j]=matrix[j][n-1-i];
                matrix[j][n-1-i]=temp;
            }
        }
    }
};
int main()
{
   vector<vector<int>>  A = {
       {5, 1, 9, 11},
       {2, 4, 8, 10},
       {13, 3, 6, 7},
       {15, 14, 12, 16}};
    Solution().rotate(A);
    int n=A.size();
    for(int i=0; i<n; ++i)
    {
      for(int j=0; j<n; ++j)
      {
        cout<<A[i][j]<<' ';
        if(j==n-1) cout<<endl;
      }
    }
    return 0;
}
