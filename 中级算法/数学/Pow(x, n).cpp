/*
输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
*/
#include<iostream>
#include<string>
using namespace std;
class Solution {
public: 
    double myPow(double x, int n) {
        if(x == 0) return 1;
        if(n == 0) return 1;
        //n取最小值时，若有绝对值会溢出
        if(n < 0) {
            double result = myPow(x, -(n+1));
            return 1.0/(x*result);
        };

        double result = myPow(x, n>>1);
        result *= result;
        if(n & 1 == 1) result *= x;
        return result;
    }
};
