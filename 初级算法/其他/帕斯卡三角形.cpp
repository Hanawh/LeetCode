/*
给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        for(int i = 0; i < numRows; ++i){
            result[i].resize(i+1); //resize()操作：创建指定数量的的元素并指定vector的存储空间
            result[i][0] = result[i][i] = 1;
            for(int j = 1; j < i; ++j){
                result[i][j] = result[i-1][j-1] + result[i-1][j];
            }
        }
        return result;
    }
};

int main(){
   int x;
   while(cin >> x){
       vector<vector<int>> temp;
       temp =  Solution().generate(x);
       for(auto &i : temp){
           for(auto &j : i){
               cout << j <<" ";
           }
           cout << endl;
       }
   }
   return 0;
}
