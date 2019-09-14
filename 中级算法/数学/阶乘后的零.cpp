/*
输入: 3
输出: 0
解释: 3! = 6, 尾数中没有零。
*/
#include<iostream>
using namespace std;
class Solution {
public: //只有乘因子有5的数字时会有零出现 有几个因子5就有几个0 f(n!) = k + f(k!), 其中 k = n / 5
    int trailingZeroes(int n) {
        int count = 0;
        while(n > 1){
            n = n/5;
            count += n;
        }
        return count;
    }
};

int main(){
   int x;
   while(cin >> x){
       cout << Solution().trailingZeroes(x) << endl;
   }
}
