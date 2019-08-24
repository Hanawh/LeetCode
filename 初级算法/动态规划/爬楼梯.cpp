/*
输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
*/

#include<iostream>
#include<vector>
using namespace std;
class Solution{
public: 
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        vector<int> num(n);
        num[0] = 1; num[1] = 2;
        for(auto i = 2; i < n; ++i){
            num[i] = num[i-1] + num[i-2];
        }
        return num[n-1];
    }
};

int main(){
    int n;
    while (cin >> n){
        cout << Solution().climbStairs(n) << endl;
    }
}
