/*
输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]
[1,2,3,4,8,12,11,10,9,5,6,7,6]
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> res;
        int m = matrix.size();
        if(m == 0) return res;
        int n = matrix[0].size();
        int up = 0, down = m-1, left = 0, right = n-1;
        //基于边界循环 边界遍历一次为一次循环
        while(up<=down and left<=right){
            int i = up, j = left;
            res.push_back(matrix[i][j]);
            //向左
            while(j < right){
                j++;
                res.push_back(matrix[i][j]);
            }
            //向下
            while(i < down){
                i++;
                res.push_back(matrix[i][j]);
            }
            //向右
            while(j > left && up != down){ //防止回传
                j--;
                res.push_back(matrix[i][j]);
            }
            //向上
            while(i > up && left != right){
                if(i-1 == up) break;
                i--;
                res.push_back(matrix[i][j]);
            }
            //更新边界
            up++;
            down--;
            left++;
            right--;
        }
        return res;
    }
};

int main(){
    int a[2][2] = {{1, 2},{3, 4}};
    vector<vector<int> > matrix(2,vector<int>(2));
    for(int i = 0; i < 2; ++i){
      for(int j = 0; j < 2; ++j){
         matrix[i][j] = a[i][j];
      }
    }
    vector<int> res = Solution().spiralOrder(matrix);
    for(auto &i : res){
        cout << i <<" ";
    }
    return 0;
}
