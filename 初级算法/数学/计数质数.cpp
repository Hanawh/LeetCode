/*
输入: 10
输出: 4
解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
*/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class Solution{
public: 
    int countPrimes(int n) {
        if(n <= 2) return 0;
        vector<int> tag(n); //tag为0表示为素数
        int count = 0;
        for(auto i = 2; i < sqrt(n); ++i){ //缩小范围从而减少循环次数
            if(tag[i] == 0){
                for(auto j = i*i; j < n; j += i){ //i*k(k<i)肯定在之前就被标记过
                    tag[j] = 1;
                }
            }
        }
        for(auto i = 2; i < n; ++i){
            if(!tag[i]) ++count; 
        }
        return count;
    }
};

int main(){
    int n;
    while(cin >> n){
        cout << Solution().countPrimes(n) << endl;
    }
    return 0;
}
