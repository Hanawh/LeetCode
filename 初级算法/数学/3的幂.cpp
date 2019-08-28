/*
输入: 27
输出: true
*/

#include<iostream>
#include<cmath>
using namespace std;
class Solution{
public: 
    bool isPowerOfThree(int n) {
        double temp = log10(n) / log10(3.0); //换底公式
        if(int(temp)-temp == 0) return true; //判断是否为整数
        return false;
    }
};

int main(){
    int n;
    while(cin >> n){
        cout << boolalpha << Solution().isPowerOfThree(n) << endl;
    }
    return 0;
}
